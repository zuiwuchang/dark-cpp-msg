#pragma once
#include "public.h"
#include "message_t.h"
#include "protocol_handler_t.h"

namespace dk
{
	namespace net
	{
		class server;
		class DARKCPPMSG_API server_t
		{
		public:
			server_t(void);
			~server_t(void);

		public:
			inline server* get_unpack()const
			{
				return _server;
			}
		protected:
			server* _server;

		private:
			server_t(const server_t& copy);
			server_t operator=(const server_t& copy);
		protected:
			//客戶端 成功連接 回調
			typedef void (*s_func_accepted_t)(server_t*,SOCKET);
			//客戶端 掉線 回調
			typedef void (*s_func_closed_t)(server_t*,SOCKET);
			//接收到 客戶端 1條完整消息後 回調
			typedef void (*s_func_readed_t)(server_t*,SOCKET,message_t*);

			//發送 1條完整消息後 回調
			typedef void (*s_func_writed_t)(server_t*,SOCKET,std::size_t);

		public:
			//向指定連接 發送 消息
			void write_message(SOCKET s,message_t& msg,error_t& e);

			//創建 服務器
			void create(unsigned short port,std::size_t buf,error_t& e);

			//返回 服務器是否 被創建
			inline operator bool() const
			{
				return _server != NULL;
			}

			//運行服務 直到 服務停止 後返回 
			//(必須已經create 否則 行為 未定義)
			void run();

			//停止服務 
			void stop();
		protected:
			void release();

		protected:
			s_func_accepted_t _func_accepted;
			s_func_closed_t _func_closed;
			s_func_readed_t _func_readed;
			s_func_writed_t _func_writed;
		public:
			//設置/返回 socket 處理 回調函數
			//設置為 NULL(默認) 不處理相應事件
			void accepted(s_func_accepted_t func);
			void closed(s_func_closed_t func);
			void readed(s_func_readed_t func);
			void writed(s_func_writed_t func);
	
			s_func_accepted_t accepted();
			s_func_closed_t closed();
			s_func_readed_t readed();
			s_func_writed_t writed();


			//返回 socket 相關信息
			void get_remote_port(SOCKET s,unsigned short& port,error_t& e);
			void get_remote_address(SOCKET s,std::string& address,error_t& e);

		protected:
			std::size_t _id;
		public:
			inline std::size_t new_id()
			{
				return ++_id;
			}
			typedef void(*D)(protocol_handler_t* handler);
			void register_protocol_handler(SOCKET s,protocol_handler_t* handler,D func = NULL);
		};
	};
};

