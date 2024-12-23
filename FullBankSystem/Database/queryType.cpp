#include "queryType.h"



QueryType::QueryType(QObject *parent)
    : QObject{parent}
{   /* Empty */   }


QueryType::QueryType(QObject *parent, Request request = Request::balance)
    : QObject{parent}, m_request{request}
{   /* Empty */   }


QString QueryType::toString()
{
    return EnumToString(m_request);
}


int QueryType::toInt()
{
    return EnumToInt(m_request);
}
