#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;

class MyPrinter {
    private:
        string str;
        int char_count;
        int thread_count;
        vector<thread> threads_vector;
        vector<std::thread::id> thread_ids_vector;
        int thread_id;
        int allowed_thread;
        mutex mutex_lock;
        condition_variable cv;
        int next_char;

    public:

        MyPrinter(string s, int c_count, int t_count) {
            str = s;
            char_count = c_count;
            thread_count = t_count;
            thread_id = 0;
            next_char = 0;
            allowed_thread = 0;
        }

        int getCurrentThreadId (const std::thread::id& id) {
            int thread_id = 0;
            for(auto& e : thread_ids_vector) {
                if(e == id) return thread_id;
                thread_id++;
            }
            return -1;
        }

        void run() {
            /**
             * Create thread_count number of threads & store their
             * details in vectors
             */
            for (int i = 0; i < thread_count; i++) {
                thread t (&MyPrinter::print_thread, this);
                cout << "Thread " << t.get_id() <<  " is " << i << endl;
                thread_ids_vector.push_back(t.get_id());
                threads_vector.push_back(move(t));
            }

            // wait for all threads to join
            for (int i = 0; i < thread_count; i++) {
                threads_vector[i].join();
            }
        }

        /**
         * this function ensures that we make progress in print_thread
         * only when all threads are created
         */
        void waitforallthreadinit() {
            while (1) {
                if (thread_count == thread_ids_vector.size())
                    return;
            }
        }

        void print_thread() {
            while (1) {
                /**
                 * ensure that all threads are created before progressing
                 * with further steps
                 */
                waitforallthreadinit ();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                unique_lock<mutex> lock(mutex_lock);
                /**
                 * wait until allowed thread reaches this point & allow
                 * only this thread to make progress
                 */
                cv.wait(lock, [this] { return std::this_thread::get_id() == thread_ids_vector[allowed_thread]; });
                // once allowed thread is available, print characters
                print_chars();

                // set next allowed thread
                allowed_thread += 1;
                allowed_thread %= thread_count;

                lock.unlock();
                cv.notify_all();
            }
        }

        void print_chars() {
            cout << "ThreadId " << getCurrentThreadId(std::this_thread::get_id()) << " : ";
            int printcount = 0;

            while (printcount < char_count) {
                cout << str[next_char];
                next_char += 1;
                next_char %= str.length();
                printcount++;
            }

            cout << endl;
        }
};

int main(int argc, char *argv[]) {

    string str = "abcdefghi";
    int char_count = 2;
    int thread_count = 3;
    
    MyPrinter p(str, char_count, thread_count);
    p.run();

    return 0;
}