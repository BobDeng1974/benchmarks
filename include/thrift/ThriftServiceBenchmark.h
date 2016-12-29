/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ThriftServiceBenchmark_H
#define ThriftServiceBenchmark_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "thrift_service_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ThriftServiceBenchmarkIf {
 public:
  virtual ~ThriftServiceBenchmarkIf() {}
  virtual int32_t get_answer(const int32_t number) = 0;
};

class ThriftServiceBenchmarkIfFactory {
 public:
  typedef ThriftServiceBenchmarkIf Handler;

  virtual ~ThriftServiceBenchmarkIfFactory() {}

  virtual ThriftServiceBenchmarkIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ThriftServiceBenchmarkIf* /* handler */) = 0;
};

class ThriftServiceBenchmarkIfSingletonFactory : virtual public ThriftServiceBenchmarkIfFactory {
 public:
  ThriftServiceBenchmarkIfSingletonFactory(const boost::shared_ptr<ThriftServiceBenchmarkIf>& iface) : iface_(iface) {}
  virtual ~ThriftServiceBenchmarkIfSingletonFactory() {}

  virtual ThriftServiceBenchmarkIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ThriftServiceBenchmarkIf* /* handler */) {}

 protected:
  boost::shared_ptr<ThriftServiceBenchmarkIf> iface_;
};

class ThriftServiceBenchmarkNull : virtual public ThriftServiceBenchmarkIf {
 public:
  virtual ~ThriftServiceBenchmarkNull() {}
  int32_t get_answer(const int32_t /* number */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _ThriftServiceBenchmark_get_answer_args__isset {
  _ThriftServiceBenchmark_get_answer_args__isset() : number(false) {}
  bool number :1;
} _ThriftServiceBenchmark_get_answer_args__isset;

class ThriftServiceBenchmark_get_answer_args {
 public:

  ThriftServiceBenchmark_get_answer_args(const ThriftServiceBenchmark_get_answer_args&);
  ThriftServiceBenchmark_get_answer_args& operator=(const ThriftServiceBenchmark_get_answer_args&);
  ThriftServiceBenchmark_get_answer_args() : number(0) {
  }

  virtual ~ThriftServiceBenchmark_get_answer_args() throw();
  int32_t number;

  _ThriftServiceBenchmark_get_answer_args__isset __isset;

  void __set_number(const int32_t val);

  bool operator == (const ThriftServiceBenchmark_get_answer_args & rhs) const
  {
    if (!(number == rhs.number))
      return false;
    return true;
  }
  bool operator != (const ThriftServiceBenchmark_get_answer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftServiceBenchmark_get_answer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ThriftServiceBenchmark_get_answer_pargs {
 public:


  virtual ~ThriftServiceBenchmark_get_answer_pargs() throw();
  const int32_t* number;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ThriftServiceBenchmark_get_answer_result__isset {
  _ThriftServiceBenchmark_get_answer_result__isset() : success(false) {}
  bool success :1;
} _ThriftServiceBenchmark_get_answer_result__isset;

class ThriftServiceBenchmark_get_answer_result {
 public:

  ThriftServiceBenchmark_get_answer_result(const ThriftServiceBenchmark_get_answer_result&);
  ThriftServiceBenchmark_get_answer_result& operator=(const ThriftServiceBenchmark_get_answer_result&);
  ThriftServiceBenchmark_get_answer_result() : success(0) {
  }

  virtual ~ThriftServiceBenchmark_get_answer_result() throw();
  int32_t success;

  _ThriftServiceBenchmark_get_answer_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const ThriftServiceBenchmark_get_answer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ThriftServiceBenchmark_get_answer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ThriftServiceBenchmark_get_answer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ThriftServiceBenchmark_get_answer_presult__isset {
  _ThriftServiceBenchmark_get_answer_presult__isset() : success(false) {}
  bool success :1;
} _ThriftServiceBenchmark_get_answer_presult__isset;

class ThriftServiceBenchmark_get_answer_presult {
 public:


  virtual ~ThriftServiceBenchmark_get_answer_presult() throw();
  int32_t* success;

  _ThriftServiceBenchmark_get_answer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ThriftServiceBenchmarkClient : virtual public ThriftServiceBenchmarkIf {
 public:
  ThriftServiceBenchmarkClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ThriftServiceBenchmarkClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t get_answer(const int32_t number);
  void send_get_answer(const int32_t number);
  int32_t recv_get_answer();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ThriftServiceBenchmarkProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ThriftServiceBenchmarkIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ThriftServiceBenchmarkProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_get_answer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ThriftServiceBenchmarkProcessor(boost::shared_ptr<ThriftServiceBenchmarkIf> iface) :
    iface_(iface) {
    processMap_["get_answer"] = &ThriftServiceBenchmarkProcessor::process_get_answer;
  }

  virtual ~ThriftServiceBenchmarkProcessor() {}
};

class ThriftServiceBenchmarkProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ThriftServiceBenchmarkProcessorFactory(const ::boost::shared_ptr< ThriftServiceBenchmarkIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ThriftServiceBenchmarkIfFactory > handlerFactory_;
};

class ThriftServiceBenchmarkMultiface : virtual public ThriftServiceBenchmarkIf {
 public:
  ThriftServiceBenchmarkMultiface(std::vector<boost::shared_ptr<ThriftServiceBenchmarkIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ThriftServiceBenchmarkMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ThriftServiceBenchmarkIf> > ifaces_;
  ThriftServiceBenchmarkMultiface() {}
  void add(boost::shared_ptr<ThriftServiceBenchmarkIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t get_answer(const int32_t number) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get_answer(number);
    }
    return ifaces_[i]->get_answer(number);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ThriftServiceBenchmarkConcurrentClient : virtual public ThriftServiceBenchmarkIf {
 public:
  ThriftServiceBenchmarkConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ThriftServiceBenchmarkConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t get_answer(const int32_t number);
  int32_t send_get_answer(const int32_t number);
  int32_t recv_get_answer(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
