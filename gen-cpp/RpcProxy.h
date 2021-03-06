/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef RpcProxy_H
#define RpcProxy_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "proxy_types.h"

namespace proxy {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class RpcProxyIf {
 public:
  virtual ~RpcProxyIf() {}
  virtual void getWebpage(std::string& _return, const std::string& url) = 0;
};

class RpcProxyIfFactory {
 public:
  typedef RpcProxyIf Handler;

  virtual ~RpcProxyIfFactory() {}

  virtual RpcProxyIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(RpcProxyIf* /* handler */) = 0;
};

class RpcProxyIfSingletonFactory : virtual public RpcProxyIfFactory {
 public:
  RpcProxyIfSingletonFactory(const boost::shared_ptr<RpcProxyIf>& iface) : iface_(iface) {}
  virtual ~RpcProxyIfSingletonFactory() {}

  virtual RpcProxyIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(RpcProxyIf* /* handler */) {}

 protected:
  boost::shared_ptr<RpcProxyIf> iface_;
};

class RpcProxyNull : virtual public RpcProxyIf {
 public:
  virtual ~RpcProxyNull() {}
  void getWebpage(std::string& /* _return */, const std::string& /* url */) {
    return;
  }
};

typedef struct _RpcProxy_getWebpage_args__isset {
  _RpcProxy_getWebpage_args__isset() : url(false) {}
  bool url :1;
} _RpcProxy_getWebpage_args__isset;

class RpcProxy_getWebpage_args {
 public:

  RpcProxy_getWebpage_args(const RpcProxy_getWebpage_args&);
  RpcProxy_getWebpage_args& operator=(const RpcProxy_getWebpage_args&);
  RpcProxy_getWebpage_args() : url() {
  }

  virtual ~RpcProxy_getWebpage_args() throw();
  std::string url;

  _RpcProxy_getWebpage_args__isset __isset;

  void __set_url(const std::string& val);

  bool operator == (const RpcProxy_getWebpage_args & rhs) const
  {
    if (!(url == rhs.url))
      return false;
    return true;
  }
  bool operator != (const RpcProxy_getWebpage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RpcProxy_getWebpage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class RpcProxy_getWebpage_pargs {
 public:


  virtual ~RpcProxy_getWebpage_pargs() throw();
  const std::string* url;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RpcProxy_getWebpage_result__isset {
  _RpcProxy_getWebpage_result__isset() : success(false) {}
  bool success :1;
} _RpcProxy_getWebpage_result__isset;

class RpcProxy_getWebpage_result {
 public:

  RpcProxy_getWebpage_result(const RpcProxy_getWebpage_result&);
  RpcProxy_getWebpage_result& operator=(const RpcProxy_getWebpage_result&);
  RpcProxy_getWebpage_result() : success() {
  }

  virtual ~RpcProxy_getWebpage_result() throw();
  std::string success;

  _RpcProxy_getWebpage_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const RpcProxy_getWebpage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const RpcProxy_getWebpage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RpcProxy_getWebpage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _RpcProxy_getWebpage_presult__isset {
  _RpcProxy_getWebpage_presult__isset() : success(false) {}
  bool success :1;
} _RpcProxy_getWebpage_presult__isset;

class RpcProxy_getWebpage_presult {
 public:


  virtual ~RpcProxy_getWebpage_presult() throw();
  std::string* success;

  _RpcProxy_getWebpage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class RpcProxyClient : virtual public RpcProxyIf {
 public:
  RpcProxyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RpcProxyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void getWebpage(std::string& _return, const std::string& url);
  void send_getWebpage(const std::string& url);
  void recv_getWebpage(std::string& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class RpcProxyProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<RpcProxyIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (RpcProxyProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getWebpage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  RpcProxyProcessor(boost::shared_ptr<RpcProxyIf> iface) :
    iface_(iface) {
    processMap_["getWebpage"] = &RpcProxyProcessor::process_getWebpage;
  }

  virtual ~RpcProxyProcessor() {}
};

class RpcProxyProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  RpcProxyProcessorFactory(const ::boost::shared_ptr< RpcProxyIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< RpcProxyIfFactory > handlerFactory_;
};

class RpcProxyMultiface : virtual public RpcProxyIf {
 public:
  RpcProxyMultiface(std::vector<boost::shared_ptr<RpcProxyIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~RpcProxyMultiface() {}
 protected:
  std::vector<boost::shared_ptr<RpcProxyIf> > ifaces_;
  RpcProxyMultiface() {}
  void add(boost::shared_ptr<RpcProxyIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getWebpage(std::string& _return, const std::string& url) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getWebpage(_return, url);
    }
    ifaces_[i]->getWebpage(_return, url);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class RpcProxyConcurrentClient : virtual public RpcProxyIf {
 public:
  RpcProxyConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  RpcProxyConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void getWebpage(std::string& _return, const std::string& url);
  int32_t send_getWebpage(const std::string& url);
  void recv_getWebpage(std::string& _return, const int32_t seqid);
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

} // namespace

#endif
