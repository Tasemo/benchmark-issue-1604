#include <benchmark/benchmark.h>
#include <iostream>

static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state) {
    std::string copy(x);
  }
}

double counter = 0.0;
BENCHMARK(BM_StringCopy)
  ->Repetitions(2)
  ->ThreadRange(1, 4)
  ->ComputeStatistics("test", [](const std::vector<double>& values) {
      std::cout << counter++ << std::endl;
      return 0.0;
    });
