#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "Logic.h"
#include "AdvancedFileOperations.h"
#include <ctime>
std::string getCurrentHour();
std::string codeToString(SYSTEM_CODE code);
void logRecord(asio::ip::tcp::socket& socket, SYSTEM_CODE code);
void processRequest(asio::ip::tcp::socket& socket, std::vector<SCHOOL>& schools);
void startServer(std::vector<SCHOOL> schools);