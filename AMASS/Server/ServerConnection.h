#pragma once
#include "Libraries.h"
#include "../CommunicationLibrary/CommunicationLibrary.h"
#include "Logic.h"
void processRequest(asio::ip::tcp::socket& socket, vector<SCHOOL> schools);
void startServer(std::vector<SCHOOL> schools);