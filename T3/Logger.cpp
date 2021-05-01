#include "Logger.h"
#include "Logger.h"
#include "Utilities.h"
const string CLogger::m_sFileName = "Log.txt";
CLogger* CLogger::m_pThis = NULL;
ofstream CLogger::m_Logfile;
CLogger::CLogger()
{
 
}
CLogger* CLogger::GetLogger(){
    if (m_pThis == NULL){
        m_pThis = new CLogger();
        m_Logfile.open(m_sFileName.c_str(), ios::out | ios::app);
    }
    return m_pThis;
}
 
void CLogger::Log(const char * format, ...)
{
    char* sMessage = NULL;
    int nLength = 0;
    va_list args;
    va_start(args, format);
    //  Return the number of characters in the string referenced the list of arguments.
    // _vscprintf doesn't count terminating '\0' (that's why +1)
    nLength = _vscprintf(format, args) + 1;
    sMessage = new char[nLength];
    // vsprintf_s(sMessage, nLength, format, args);
    vsprintf(sMessage, format, args);
    m_Logfile << Util::CurrentDateTime() << " ==>   ";
    m_Logfile << sMessage << "\n";
    va_end(args);
 
    delete [] sMessage;
}
 
void CLogger::Log(const string& sMessage)
{
    m_Logfile <<  Util::CurrentDateTime() << " ==>   ";
    m_Logfile << sMessage << "\n";
}
 
CLogger& CLogger::operator<<(const string& sMessage)
{
    m_Logfile << "\n" << Util::CurrentDateTime() << " ==>   ";
    m_Logfile << sMessage << "\n";
    return *this;
}