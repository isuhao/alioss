/*-----------------------------------------------
File	: service.h
Date	: Nov 6, 2014
Author	: twofei <anhbk@qq.com>
-----------------------------------------------*/

#include <stdint.h>

#include <string>
#include <sstream>
#include <vector>

#include "socket.h"
#include "accesskey.h"
#include "ossmeta.h"

namespace alioss {

namespace service{

class service {
private:
	class body_stream : public stream::ostream {
	public:
		virtual int size() const override {
			return static_cast<int>(_buffer.size());
		}

		virtual int write_some(const unsigned char* buf, int sz) override
		{
			_buffer += std::string((char*)buf, sz);
			return sz;
		}

	public:
		unsigned char* data() {
			return (unsigned char*)_buffer.c_str();
		}

	protected:
		std::string _buffer;
	};

public:
	service()
	{}
	
	bool connect();
	bool disconnect();

	void set_key(const char* id, const char* secret){
		_key.set_key(id, secret);
	}

	bool query();

protected:
	bool request();
	bool response();

	bool parse_response_body(const char* data, int size);

private:
	// avoid copy-ctor on vector::push_back()
	meta::bucket& bucket_create() {
		_buckets.push_back(meta::bucket());
		return _buckets[_buckets.size() - 1];
	}

protected:
	std::string		_prefix;
	std::string		_marker;
	std::string		_max_keys;
	bool			_is_truncated;
	std::string		_next_marker;

protected:
	meta::owner _owner;
	std::vector<meta::bucket> _buckets;

protected:
	accesskey	_key;
	http::http	_http;
};

} // namespace service

} // namespace alioss
