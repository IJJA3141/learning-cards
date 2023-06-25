#pragma once
#ifndef DEBUG
#define DEBUG

#ifdef _DEBUG
#define LOG(x) std::cout << x << "\n";

#else
#define LOG(x) ;

#endif // _DEBUG
#endif // !DEBUG
