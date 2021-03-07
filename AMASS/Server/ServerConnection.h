#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "Logic.h"
#include <ctime>
DATE getCurrentDate();
string codeToString(SYSTEM_CODE code);
void logRecord(asio::ip::tcp::socket& socket, SYSTEM_CODE code);
void processRequest(asio::ip::tcp::socket& socket, vector<SCHOOL>& schools);
void startServer(std::vector<SCHOOL> schools);