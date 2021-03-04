#pragma once
#include <asio.hpp>
void saveStr(asio::ip::tcp::socket& socket, std::string str);
void saveInt(asio::ip::tcp::socket& socket, int integer);
void saveBool(asio::ip::tcp::socket& socket, bool a);
void readStr(asio::ip::tcp::socket& socket, std::string& str, int size);
void readInt(asio::ip::tcp::socket& socket, int& num);
void readShortInt(asio::ip::tcp::socket& socket, uint16_t& num);
void readBool(asio::ip::tcp::socket& socket, bool& a);