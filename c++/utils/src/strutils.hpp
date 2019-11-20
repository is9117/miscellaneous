
#pragma once

#include <cstring>
#include <string>
#include <vector>

#define IN
#define OUT
#define INOUT

namespace strutils
{
    class CTrimPattern
    {
    public:
        CTrimPattern(const char* a_szWSChars);
        inline bool MatchesChar(char a_cToken)
        {
            return m_abCharOneHotFlags[a_cToken];
        }

    private:
        bool m_abCharOneHotFlags[256];
    };

    /*
    Params:
    - a_pcStart: starting string pointer
    - a_pcEnd: next to '\0' char pointer
               ex) char a* = "abc\0"; a_pcEnd = a + strlen(a) + 1;
               char in [a_pcStart, a_pcEnd) will be modified.
    - a_vcStr: char vector to split. a_vcStr wilil be modified.
    - a_szStr: null terminated string pointer. will look for end pointer using strlen()
    - a_cWSChar: one char token
    - a_szWSChars: token char array(null terminated)
    - a_poPattern: pre-initialized pattern object. use this if need to trim same pattern multiple times.
    */
    const char*	ltrim( INOUT std::vector<char> &a_vcStr, 			IN char a_cWSChar);
    const char*	ltrim( INOUT char* a_szStr, 						IN char a_cWSChar);
    const char*	ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd, 	IN char a_cWSChar);
    void		ltrim( INOUT std::string &a_csStr, 					IN char a_cWSChar);
    void		rtrim( INOUT std::vector<char> &a_vcStr, 			IN char a_cWSChar);
    void		rtrim( INOUT INOUT char* a_szStr, 					IN char a_cWSChar);
    void		rtrim( INOUT char* a_pcStart, INOUT char* a_pcEnd,	IN char a_cWSChar);
    void		rtrim( INOUT std::string &a_csStr, 					IN char a_cWSChar);
    const char*	trim ( INOUT std::vector<char> &a_vcStr, 			IN char a_cWSChar);
    const char*	trim ( INOUT char* a_szStr, 						IN char a_cWSChar);
    const char*	trim ( INOUT char* a_pcStart, INOUT char* a_pcEnd, 	IN char a_cWSChar);
    void		trim ( INOUT std::string &a_csStr, 					IN char a_cWSChar);
    
    const char*	ltrim( INOUT std::vector<char> &a_vcStr, 			IN const char* a_szWSChars);
    const char*	ltrim( INOUT char* a_szStr, 						IN const char* a_szWSChars);
    const char*	ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd,	IN const char* a_szWSChars);
    void		rtrim( INOUT std::vector<char> &a_vcStr, 			IN const char* a_szWSChars);
    void		rtrim( INOUT char* a_szStr, 						IN const char* a_szWSChars);
    void		rtrim( INOUT char* a_pcStart, INOUT char* a_pcEnd,	IN const char* a_szWSChars);
    const char* trim ( INOUT std::vector<char> &a_vcStr, 			IN const char* a_szWSChars);
    const char* trim ( INOUT char* a_szStr, 						IN const char* a_szWSChars);
    const char* trim ( INOUT char* a_pcStart, INOUT char* a_pcEnd, 	IN const char* a_szWSChars);

    const char*	ltrim( INOUT std::vector<char> &a_vcStr, 			IN CTrimPattern &a_poPattern);
    const char*	ltrim( INOUT char* a_szStr, 						IN CTrimPattern &a_poPattern);
    const char*	ltrim( INOUT char* a_pcStart, INOUT char* a_pcEnd,	IN CTrimPattern &a_poPattern);
    void		rtrim( INOUT std::vector<char> &a_vcStr, 			IN CTrimPattern &a_poPattern);
    void		rtrim( INOUT char* a_szStr, 						IN CTrimPattern &a_poPattern);
    void		rtrim( INOUT char* a_pcStart, INOUT char* a_pcEnd,	IN CTrimPattern &a_poPattern);
    const char* trim ( INOUT std::vector<char> &a_vcStr, 			IN CTrimPattern &a_poPattern);
    const char* trim ( INOUT char* a_szStr, 						IN CTrimPattern &a_poPattern);
    const char* trim ( INOUT char* a_pcStart, INOUT char* a_pcEnd, 	IN CTrimPattern &a_poPattern);

    /*
    Params:
    - a_pcStart: starting string pointer
    - a_pcEnd: next to '\0' char pointer
               ex) char a* = "abc\0"; a_pcEnd = a + strlen(a) + 1;
               char in [a_pcStart, a_pcEnd) will be modified.
    - a_vcStr: char vector to split. a_vcStr wilil be modified.
    - a_szStr: null terminated string pointer. will look for end pointer using strlen()
    - a_vpcOut: split output(char* vector). pointers in [a_pcStart, a_pcEnd).
    - a_cSplitToken: 1 ~ 2 size char split token value.
    */
    void split( INOUT std::vector<char> &a_vcStr, 			OUT std::vector<const char*> &a_vpcOut, IN char a_cSplitToken);
    void split( INOUT std::vector<char> &a_vcStr, 			OUT std::vector<const char*> &a_vpcOut,	IN char a_caSplitToken[2]);
    void split(	INOUT char* a_szStr, 						OUT std::vector<const char*> &a_vpcOut,	IN char a_cSplitToken);
    void split(	INOUT char* a_szStr, 						OUT std::vector<const char*> &a_vpcOut,	IN char a_caSplitToken[2]);
    void split(	INOUT char* a_pcStart, INOUT char* a_pcEnd,	OUT std::vector<const char*> &a_vpcOut,	IN char a_cSplitToken);
    void split(	INOUT char* a_pcStart, INOUT char* a_pcEnd, OUT std::vector<const char*> &a_vpcOut,	IN char a_caSplitToken[2]);
}
