#pragma once
#include <asio.hpp>
void writeShortInt(asio::ip::tcp::socket& socket, uint16_t num);
void writeStr(asio::ip::tcp::socket& socket, std::string str);
void writeInt(asio::ip::tcp::socket& socket, int integer);
void writeBool(asio::ip::tcp::socket& socket, bool a);
void writeVec(asio::ip::tcp::socket& socket, std::vector<int> vec);
void writeVec(asio::ip::tcp::socket& socket, std::vector<std::string> vec);
void readStr(asio::ip::tcp::socket& socket, std::string& str);
void readInt(asio::ip::tcp::socket& socket, int& num);
void readShortInt(asio::ip::tcp::socket& socket, uint16_t& num);
void readBool(asio::ip::tcp::socket& socket, bool& a);
void readVec(asio::ip::tcp::socket& socket, std::vector<std::string>& vec);
void readVec(asio::ip::tcp::socket& socket, std::vector<int>& vec);