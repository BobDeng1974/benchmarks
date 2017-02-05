#pragma once

#ifndef FIXTURE_H_NNOJDJZG
#define FIXTURE_H_NNOJDJZG

#include "benchmark/benchmark.h"

#include "capnp/ez-rpc.h"

#include "target_code.h"

#include "capnp/capnp_service.capnp.h"

class capnp_bench : public benchmark::Fixture {
private:
  static int blob_size_;
  class capnp_server : public CapnpServiceBenchmark::Server {
  public:
    kj::Promise<void> getAnswer(GetAnswerContext context) override {
      auto num = context.getParams().getNumber();
      context.getResults().setResult(::get_answer(num));
      return kj::READY_NOW;
    }

    kj::Promise<void> getBlob(GetBlobContext context) override {
      auto blob = ::get_blob(blob_size_);
      kj::ArrayPtr<unsigned char> arr((unsigned char *)blob.data(),
                                      blob.size());
      context.getResults().setResult(capnp::Data::Reader(arr));
      return kj::READY_NOW;
    }
  };

public:
  capnp_bench()
      : server(kj::heap<capnp_server>(), "127.0.0.1:8081"),
        reader_options{256 * 1024 * 1024, 64},
        client_thing("127.0.0.1:8081", 8080, reader_options),
        client(client_thing.getMain<CapnpServiceBenchmark>()) {
    auto &wait_scope = server.getWaitScope();
    server.getPort().wait(wait_scope);
  }

  void get_answer(int param) {
    (void)param;
    auto request = client.getAnswerRequest();
    request.setNumber(23);
    auto resultPromise = request.send();
    int a;
    benchmark::DoNotOptimize(
        a = resultPromise.wait(client_thing.getWaitScope()).getResult());
  }

  void get_blob(int param) {
    blob_size_ = param;
    auto request = client.getBlobRequest();
    auto resultPromise = request.send();
    std::string s;
    auto result =
        resultPromise.wait(client_thing.getWaitScope()).getResult().asChars();
    benchmark::DoNotOptimize(s = result.begin());
  }

  ~capnp_bench() noexcept {}

  capnp::EzRpcServer server;
  capnp::ReaderOptions reader_options;
  capnp::EzRpcClient client_thing;
  CapnpServiceBenchmark::Client client;
};

#endif /* end of include guard: FIXTURE_H_NNOJDJZG */