#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <string>
#include <vector>

#include "strutils.hpp"



using namespace std;

TEST_CASE( "string ltrim test", "[strutils]")
{
	string csTarget = "   some test string";
    strutils::CTrimPattern oPattern(" ");

    SECTION( "ltrim(char*, char*, ..., char) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(&vcStr[0], &*vcStr.end(), ' ');
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(char*, char*, ..., char*) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(&vcStr[0], &*vcStr.end(), " ");
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(char*, char*, ..., CTrimPattern&) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(&vcStr[0], &*vcStr.end(), oPattern);
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(char*, ..., char) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(&vcStr[0], ' ');
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(char*, ..., char*) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(&vcStr[0], " ");
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(char*, ..., CTrimPattern&) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(&vcStr[0], oPattern);
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(vector<char>, ..., char) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(vcStr, ' ');
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(vector<char>, ..., char*) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(vcStr, " ");
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(vector<char>, ..., CTrimPattern&) test", "[strutils::ltrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::ltrim(vcStr, oPattern);
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "ltrim(std::string, ..., char) test", "[strutils::ltrim]" )
    {
        strutils::ltrim(csTarget, ' ');
        REQUIRE( csTarget ==  "some test string" );
    }
}

TEST_CASE( "string rtrim test", "[strutils]")
{
	string csTarget = "some test string   ";
    strutils::CTrimPattern oPattern(" ");

    SECTION( "rtrim(char*, char*, ..., char) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(&vcStr[0], &*vcStr.end(), ' ');
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(char*, char*, ..., char*) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(&vcStr[0], &*vcStr.end(), " ");
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(char*, char*, ..., CTrimPattern&) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(&vcStr[0], &*vcStr.end(), oPattern);
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(char*, ..., char) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(&vcStr[0], ' ');
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(char*, ..., char*) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(&vcStr[0], " ");
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(char*, ..., CTrimPattern&) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(&vcStr[0], oPattern);
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(vector<char>, ..., char) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(vcStr, ' ');
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(vector<char>, ..., char*) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(vcStr, " ");
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(vector<char>, ..., CTrimPattern&) test", "[strutils::rtrim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        strutils::rtrim(vcStr, oPattern);
        REQUIRE( string(&vcStr[0]) ==  "some test string" );
    }

    SECTION( "rtrim(std::string, ..., char) test", "[strutils::rtrim]" )
    {
        strutils::rtrim(csTarget, ' ');
        REQUIRE( csTarget ==  "some test string" );
    }
}

TEST_CASE( "string trim test", "[strutils]")
{
	string csTarget = "   some test string        ";
    strutils::CTrimPattern oPattern(" ");

    SECTION( "trim(char*, char*, ..., char) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(&vcStr[0], &*vcStr.end(), ' ');
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(char*, char*, ..., char*) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(&vcStr[0], &*vcStr.end(), " ");
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(char*, char*, ..., CTrimPattern&) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(&vcStr[0], &*vcStr.end(), oPattern);
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(char*, ..., char) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(&vcStr[0], ' ');
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(char*, ..., char*) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(&vcStr[0], " ");
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(char*, ..., CTrimPattern&) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(&vcStr[0], oPattern);
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(vector<char>, ..., char) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(vcStr, ' ');
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(vector<char>, ..., char*) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(vcStr, " ");
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(vector<char>, ..., CTrimPattern&) test", "[strutils::trim]" )
    {
        vector<char> vcStr(csTarget.begin(), csTarget.end());
        vcStr.push_back('\0');
        const char* pcResult = strutils::trim(vcStr, oPattern);
        REQUIRE( string(pcResult) ==  "some test string" );
    }

    SECTION( "trim(std::string, ..., char) test", "[strutils::trim]" )
    {
        strutils::trim(csTarget, ' ');
        REQUIRE( csTarget ==  "some test string" );
    }
}


TEST_CASE( "string split test", "[strutils]" )
{
    string csTarget = 
    "some line of string\n"
    "and another line of string\n"
    "more line of string\n"
    "final line of string";

    string csTarget2 = 
    "some line of string\r\n"
    "and another line of string\r\n"
    "more line of string\r\n"
    "final line of string";


    SECTION( "split(char*, char*, ...) test", "[strutils::split]" )
    {
        vector<char> vcTarget(csTarget.begin(), csTarget.end() + 1);
        vector<const char*> vpcOutputVector;
        char* pcStart = &vcTarget[0];
        char* pcEnd = &*vcTarget.end();

        strutils::split(pcStart, pcEnd, vpcOutputVector, '\n');

        REQUIRE( vpcOutputVector.size() == 4 );
        REQUIRE( string(vpcOutputVector[0]) == "some line of string" );
        REQUIRE( string(vpcOutputVector[3]) == "final line of string" );
    }

    SECTION( "split(char*, ...) test", "[strutils::split]" )
    {
        vector<char> vcTarget(csTarget.begin(), csTarget.end() + 1);
        vector<const char*> vpcOutputVector;
        char* pcStart = &vcTarget[0];

        strutils::split(pcStart, vpcOutputVector, '\n');

        REQUIRE( vpcOutputVector.size() == 4 );
        REQUIRE( string(vpcOutputVector[0]) == "some line of string" );
        REQUIRE( string(vpcOutputVector[3]) == "final line of string" );
    }

    SECTION( "split(vector<char>&, ...) test", "[strutils::split]" )
    {
        vector<char> vcTarget(csTarget.begin(), csTarget.end() + 1);
        vector<const char*> vpcOutputVector;

        strutils::split(vcTarget, vpcOutputVector, '\n');

        REQUIRE( vpcOutputVector.size() == 4 );
        REQUIRE( string(vpcOutputVector[0]) == "some line of string" );
        REQUIRE( string(vpcOutputVector[3]) == "final line of string" );
    }

    SECTION( "split(char*, char*, ... with 2 byte token) test", "[strutils::split]" )
    {
        vector<char> vcTarget(csTarget2.begin(), csTarget2.end() + 1);
        vector<const char*> vpcOutputVector;
        char* pcStart = &vcTarget[0];
        char* pcEnd = &*vcTarget.end();

        strutils::split(pcStart, pcEnd, vpcOutputVector, "\r\n");

        REQUIRE( vpcOutputVector.size() == 4 );
        REQUIRE( string(vpcOutputVector[0]) == "some line of string" );
        REQUIRE( string(vpcOutputVector[3]) == "final line of string" );
    }

    SECTION( "split(char*, ... with 2 byte token) test", "[strutils::split]" )
    {
        vector<char> vcTarget(csTarget2.begin(), csTarget2.end() + 1);
        vector<const char*> vpcOutputVector;
        char* pcStart = &vcTarget[0];

        strutils::split(pcStart, vpcOutputVector, "\r\n");

        REQUIRE( vpcOutputVector.size() == 4 );
        REQUIRE( string(vpcOutputVector[0]) == "some line of string" );
        REQUIRE( string(vpcOutputVector[3]) == "final line of string" );
    }

    SECTION( "split(vector<char>&, ... with 2 byte token) test", "[strutils::split]" )
    {
        vector<char> vcTarget(csTarget2.begin(), csTarget2.end() + 1);
        vector<const char*> vpcOutputVector;

        strutils::split(vcTarget, vpcOutputVector, "\r\n");

        REQUIRE( vpcOutputVector.size() == 4 );
        REQUIRE( string(vpcOutputVector[0]) == "some line of string" );
        REQUIRE( string(vpcOutputVector[3]) == "final line of string" );
    }
}