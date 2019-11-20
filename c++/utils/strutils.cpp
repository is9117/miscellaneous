


#include "strutils.hpp"

#include <stdexcept>
#include <algorithm>

using namespace std;


/*
std::string trim algorithm is referenced from:
https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
*/


/*************************************************/
/*********** strutils::CTrimPattern **************/
/*************************************************/

strutils::CTrimPattern::CTrimPattern(const char* a_szWSChars)
{
    if(a_szWSChars == nullptr || strlen(a_szWSChars) == 0)
        throw runtime_error("[strutils::CTrimPattern::CTrimPattern] invalid input");
    
    memset(m_abCharOneHotFlags, 0, sizeof(m_abCharOneHotFlags));
    for(int i = 0; i < strlen(a_szWSChars); i++)
        m_abCharOneHotFlags[a_szWSChars[i]] = true;
};

/*************************************************/
/*************** strutils::ltrim *****************/
/*************************************************/

static inline 
const char* __ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN char a_cWSChar)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return nullptr;

    char* iter = a_pcStart;
    while(iter < a_pcEnd && *iter == a_cWSChar)
        iter++;

    return iter;
}

static inline 
const char* __ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN const char* a_szWSChars)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return nullptr;

    bool aCharOneHotFlags[256] = {0, };
    for(int i = 0; i < strlen(a_szWSChars); i++)
        aCharOneHotFlags[a_szWSChars[i]] = true;

    char* iter = a_pcStart;
    while(iter < a_pcEnd && aCharOneHotFlags[*iter] == true)
        iter++;

    return iter;
}

static inline 
const char* __ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN strutils::CTrimPattern &a_oPattern)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return nullptr;

    char* iter = a_pcStart;
    while(iter < a_pcEnd && a_oPattern.MatchesChar(*iter))
        iter++;

    return iter;
}

const char* strutils::ltrim( INOUT std::vector<char> &a_vcStr, IN char a_cWSChar)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    return __ltrim(pcStart, pcEnd, a_cWSChar);
}

const char* strutils::ltrim( INOUT std::vector<char> &a_vcStr, IN const char* a_szWSChars)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    return __ltrim(pcStart, pcEnd, a_szWSChars);
}

const char* strutils::ltrim( INOUT std::vector<char> &a_vcStr, IN CTrimPattern &a_oPattern)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    return __ltrim(pcStart, pcEnd, a_oPattern);
}

const char* strutils::ltrim( INOUT char* a_szStr, IN char a_cWSChar)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    return __ltrim(a_szStr, pcEnd, a_cWSChar);
}

const char* strutils::ltrim( INOUT char* a_szStr, IN const char* a_szWSChars)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    return __ltrim(a_szStr, pcEnd, a_szWSChars);
}

const char* strutils::ltrim( INOUT char* a_szStr, IN CTrimPattern &a_oPattern)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    return __ltrim(a_szStr, pcEnd, a_oPattern);
}

const char* strutils::ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN char a_cWSChar)
{
    return __ltrim(a_pcStart, a_pcEnd, a_cWSChar);
}

const char* strutils::ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN const char* a_szWSChars)
{
    return __ltrim(a_pcStart, a_pcEnd, a_szWSChars);
}

const char* strutils::ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN CTrimPattern &a_oPattern)
{
    return __ltrim(a_pcStart, a_pcEnd, a_oPattern);
}

void strutils::ltrim(INOUT std::string &a_csStr, IN char a_cWSChar)
{
    a_csStr.erase(a_csStr.begin(), std::find_if(a_csStr.begin(), a_csStr.end(), [a_cWSChar](int ch) {
        return ch != a_cWSChar;
    }));
}

/*************************************************/
/*************** strutils::rtrim *****************/
/*************************************************/


static inline 
void __rtrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN char a_cWSChar)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return;

    // Because a_pcEnd is next to '\0' pointer.
    // To iterate from rear end of string, need to skip 2 addresses.
    char* iter = ----a_pcEnd;	
    while(iter > a_pcStart && *iter == a_cWSChar)
        iter--;

    if(++iter != a_pcEnd)
        *iter = '\0';
}

static inline 
void __rtrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN const char* a_szWSChars)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return;

    bool aCharOneHotFlags[256] = {0, };
    for(int i = 0; i < strlen(a_szWSChars); i++)
        aCharOneHotFlags[a_szWSChars[i]] = true;

    // Because a_pcEnd is next to '\0' pointer.
    // To iterate from rear end of string, need to skip 2 addresses.
    char* iter = ----a_pcEnd;	
    while(iter > a_pcStart && aCharOneHotFlags[*iter] == true)
        iter--;

    if(++iter != a_pcEnd)
        *iter = '\0';
}

static inline 
void __rtrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN strutils::CTrimPattern &a_oPattern)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return;

    // Because a_pcEnd is next to '\0' pointer.
    // To iterate from rear end of string, need to skip 2 addresses.
    char* iter = ----a_pcEnd;	
    while(iter > a_pcStart && a_oPattern.MatchesChar(*iter))
        iter--;

    if(++iter != a_pcEnd)
        *iter = '\0';
}

void strutils::rtrim( INOUT std::vector<char> &a_vcStr, IN char a_cWSChar)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __rtrim(pcStart, pcEnd, a_cWSChar);
}

void strutils::rtrim( INOUT std::vector<char> &a_vcStr, IN const char* a_szWSChars)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __rtrim(pcStart, pcEnd, a_szWSChars);
}

void strutils::rtrim( INOUT std::vector<char> &a_vcStr, IN CTrimPattern &a_oPattern)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __rtrim(pcStart, pcEnd, a_oPattern);
}

void strutils::rtrim( INOUT INOUT char* a_szStr, IN char a_cWSChar)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __rtrim(a_szStr, pcEnd, a_cWSChar);
}

void strutils::rtrim( INOUT INOUT char* a_szStr, IN const char* a_szWSChars)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __rtrim(a_szStr, pcEnd, a_szWSChars);
}

void strutils::rtrim( INOUT INOUT char* a_szStr, IN CTrimPattern &a_oPattern)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __rtrim(a_szStr, pcEnd, a_oPattern);
}

void strutils::rtrim( INOUT INOUT char* a_pcStart, INOUT char* a_pcEnd, IN char a_cWSChar)
{
    __rtrim(a_pcStart, a_pcEnd, a_cWSChar);
}

void strutils::rtrim( INOUT INOUT char* a_pcStart, INOUT char* a_pcEnd, IN const char* a_szWSChars)
{
    __rtrim(a_pcStart, a_pcEnd, a_szWSChars);
}

void strutils::rtrim( INOUT INOUT char* a_pcStart, INOUT char* a_pcEnd, IN CTrimPattern &a_oPattern)
{
    __rtrim(a_pcStart, a_pcEnd, a_oPattern);
}

void strutils::rtrim(INOUT std::string &a_csStr, IN char a_cWSChar)
{
    a_csStr.erase(std::find_if(a_csStr.rbegin(), a_csStr.rend(), [a_cWSChar](int ch) {
        return ch != a_cWSChar;
    }).base(), a_csStr.end());
}



/*************************************************/
/*************** strutils::trim ******************/
/*************************************************/


const char* strutils::trim( INOUT std::vector<char> &a_vcStr, IN char a_cWSChar)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __rtrim(pcStart, pcEnd, a_cWSChar);
    pcEnd = pcStart + strlen(pcStart) + 1;
    return __ltrim(pcStart, pcEnd, a_cWSChar);
}

const char* strutils::trim( INOUT std::vector<char> &a_vcStr, IN const char* a_szWSChars)
{
    CTrimPattern oPattern(a_szWSChars);
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __rtrim(pcStart, pcEnd, oPattern);
    pcEnd = pcStart + strlen(pcStart) + 1;
    return __ltrim(pcStart, pcEnd, oPattern);
}

const char* strutils::trim( INOUT std::vector<char> &a_vcStr, IN CTrimPattern &a_oPattern)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __rtrim(pcStart, pcEnd, a_oPattern);
    pcEnd = pcStart + strlen(pcStart) + 1;
    return __ltrim(pcStart, pcEnd, a_oPattern);
}

const char* strutils::trim( INOUT char* a_szStr, IN char a_cWSChar)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __rtrim(a_szStr, pcEnd, a_cWSChar);
    pcEnd = a_szStr + strlen(a_szStr) + 1;
    return __ltrim(a_szStr, pcEnd, a_cWSChar);
}

const char* strutils::trim( INOUT char* a_szStr, IN const char* a_szWSChars)
{
    CTrimPattern oPattern(a_szWSChars);
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __rtrim(a_szStr, pcEnd, oPattern);
    pcEnd = a_szStr + strlen(a_szStr) + 1;
    return __ltrim(a_szStr, pcEnd, oPattern);
}

const char* strutils::trim( INOUT char* a_szStr, IN CTrimPattern &a_oPattern)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __rtrim(a_szStr, pcEnd, a_oPattern);
    pcEnd = a_szStr + strlen(a_szStr) + 1;
    return __ltrim(a_szStr, pcEnd, a_oPattern);
}

const char* strutils::trim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN char a_cWSChar)
{
    __rtrim(a_pcStart, a_pcEnd, a_cWSChar);
    char* pcEnd = a_pcStart + strlen(a_pcStart) + 1;
    return __ltrim(a_pcStart, pcEnd, a_cWSChar);
}

const char* strutils::trim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN const char* a_szWSChars)
{
    CTrimPattern oPattern(a_szWSChars);
    __rtrim(a_pcStart, a_pcEnd, oPattern);
    char* pcEnd = a_pcStart + strlen(a_pcStart) + 1;
    return __ltrim(a_pcStart, pcEnd, oPattern);
}

const char* strutils::trim( INOUT char* a_pcStart, INOUT char* a_pcEnd, IN CTrimPattern &a_oPattern)
{
    __rtrim(a_pcStart, a_pcEnd, a_oPattern);
    char* pcEnd = a_pcStart + strlen(a_pcStart) + 1;
    return __ltrim(a_pcStart, pcEnd, a_oPattern);
}

void strutils::trim(INOUT std::string &a_csStr, IN char a_cWSChar)
{
    ltrim(a_csStr, a_cWSChar);
    rtrim(a_csStr, a_cWSChar);
}


/*************************************************/
/*************** strutils::split *****************/
/*************************************************/


static inline
void __split(INOUT char* a_pcStart, INOUT char* a_pcEnd, OUT vector<const char*> &a_vpcOut, IN char a_cSplitToken)
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return;
    
    const char* szLine = (const char*)a_pcStart;
    char* iter = a_pcStart;
    char* end = a_pcEnd;
    while(iter < end)
    {
        for(;iter < end; iter++)
        {
            if(*iter == a_cSplitToken)
            {
                *iter = '\0';
                break;
            }
        }

        a_vpcOut.push_back(szLine);

        // set char* array with next char pointer
        szLine = (const char*)++iter;
    }
}


static inline
void __split(INOUT char* a_pcStart, INOUT char* a_pcEnd, OUT vector<const char*> &a_vpcOut, IN char a_caSplitToken[2])
{
    if(a_pcStart == nullptr || a_pcEnd == nullptr)
        return;
    
    unsigned short usToken = *(unsigned short*)a_caSplitToken;
    const char* szLine = (const char*)a_pcStart;
    char* iter = a_pcStart;
    char* end = a_pcEnd;
    while(iter < end)
    {
        for(;iter < end; iter++)
        {
            if(*(unsigned short*)iter == usToken)
            {
                iter[0] = '\0';
                iter[1] = '\0';
                break;
            }
        }

        a_vpcOut.push_back(szLine);

        // set char* array with next char pointer
        szLine = (const char*)++++iter;
    }
}


void strutils::split(INOUT vector<char> &a_vcStr, OUT vector<const char*> &a_vpcOut, IN char a_cSplitToken)
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __split(pcStart, pcEnd, a_vpcOut, a_cSplitToken);
}


void strutils::split(INOUT vector<char> &a_vcStr, OUT vector<const char*> &a_vpcOut, IN char a_caSplitToken[2])
{
    char* pcStart = &a_vcStr[0];
    char* pcEnd = &*a_vcStr.end();
    __split(pcStart, pcEnd, a_vpcOut, a_caSplitToken);
}

void strutils::split(INOUT char* a_szStr, OUT vector<const char*> &a_vpcOut, IN char a_cSplitToken)
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __split(a_szStr, pcEnd, a_vpcOut, a_cSplitToken);
}

void strutils::split(INOUT char* a_szStr, OUT vector<const char*> &a_vpcOut, IN char a_caSplitToken[2])
{
    char* pcEnd = a_szStr + strlen(a_szStr) + 1;
    __split(a_szStr, pcEnd, a_vpcOut, a_caSplitToken);
}

void strutils::split(INOUT char* a_pcStart, INOUT char* a_pcEnd, OUT vector<const char*> &a_vpcOut, IN char a_cSplitToken)
{
    __split(a_pcStart, a_pcEnd, a_vpcOut, a_cSplitToken);
}

void strutils::split(INOUT char* a_pcStart, INOUT char* a_pcEnd, OUT vector<const char*> &a_vpcOut, IN char a_caSplitToken[2])
{
    __split(a_pcStart, a_pcEnd, a_vpcOut, a_caSplitToken);
}
