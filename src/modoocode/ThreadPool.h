#pragma once
#include <vector>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
public:
	ThreadPool() noexcept;
	virtual ~ThreadPool() noexcept;

public:
	void WorkerThread();
	void EnqueueJob(std::function<void()> job);

private:
	size_t num_threads_;
	std::vector<std::thread> worker_threads_;
	std::queue<std::function<void()>> jobs_;
	std::condition_variable cv_job_q_;
	std::mutex m_job_q_;
	bool stop_all;
}; //class ThreadPool