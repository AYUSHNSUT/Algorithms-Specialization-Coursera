#include <iostream>
#include <queue>
#include <vector>

#define DEBUG(x) std::cout << '>' << #x << ':' << x << std::endl;

struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time)
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
  // /      time_(time),
        finish_time_()
    {}

    Response Process(const Request &request) {
        // write your code here
    //    DEBUG(finish_time_.size());
    //     if(finish_time_.empty())
    //     {
    //   //    printf("1\n");
    //       bool dropped = false;
    //     //  elems++;
    //       int st = request.arrival_time;
    //       finish_time_.push(st+request.process_time);
    //       Response r(dropped, st);
    //
    //       return r;
    //     }
    //
    //     else if(finish_time_.size()<size_ ||( finish_time_.size()==size_ && finish_time_.front() <= request.arrival_time))
    //     {
    // //    DEBUG(finish_time_.front());
    // //      DEBUG(request.arrival_time);
    //     //  printf("2\n");
    //       //if(( finish_time_.size()==size_ && finish_time_.front() <= request.arrival_time))
    //     //    printf("lol");
    //       while((!finish_time_.empty()) && finish_time_.front()<=request.arrival_time)
    //       {
    //       //  DEBUG(finish_time_.empty());
    //         time_= time_ + finish_time_.front();
    //         finish_time_.pop();
    //
    //       }
    //
    //       bool dropped = false;
    //     //  elems++;
    //       int st = request.arrival_time;
    //       finish_time_.push(std::max(st+request.process_time,finish_time_.front() + request.process_time));
    //       if(time_ > st)
    //       {
    //         st = time_;
    //       }
    //       //else
    //     //  time_ = st;
    //       Response r(dropped, st);
    //       return r;

    while (!finish_time_.empty() && finish_time_.front()<=request.arrival_time) {
          finish_time_.pop();
		}

		if (finish_time_.size() == size_)
            return Response(true, -1);

		if (finish_time_.empty()){
            finish_time_.push(request.arrival_time + request.process_time);
            return Response(false, request.arrival_time);
		}

		int last_element = finish_time_.back();
        finish_time_.push(last_element + request.process_time);
        return Response(false, last_element);

        }
  //
  //       else
  //       {
  //     //    printf("3\n");
  // //    DEBUG(finish_time_.front());
  // //    DEBUG(request.arrival_time);
  //         bool dropped = true;
  //         int st = request.arrival_time;
  //       //  finish_time_.push(st+request.process_time);
  //         Response r(dropped, st);
  //         return r;
  //       }

private:
    int size_;
  //  int elems = 0;
  //  int time_;
    std::queue <int> finish_time_;
};

std::vector <Request> ReadRequests() {
    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
    {
      responses.push_back(buffer->Process(requests[i]));
    //  printf("\n*************************************\n");
    }

    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
