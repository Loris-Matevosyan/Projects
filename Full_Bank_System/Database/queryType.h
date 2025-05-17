#ifndef QUERYTYPE_H
#define QUERYTYPE_H

#include <concepts>
#include <QObject>
#include <QString>
#include <QMetaEnum>



template <typename T>
concept EnumClass = std::is_scoped_enum_v<T>;


template <typename EnumClass>
int EnumToInt(EnumClass arg)
{
    int castValue = static_cast<int>(arg);
    return castValue;
}


template <typename EnumClass>
QString EnumToString(EnumClass arg)
{
    int castValue = static_cast<int>(arg);
    return QMetaEnum::fromType<EnumClass>().valueToKey(castValue);
}



class QueryType : public QObject
{
private:
    Q_OBJECT

public:
    enum class Request
    {
        information,
        balance,
        history
    };
    Q_ENUM(Request);

    QueryType(QObject *parent = nullptr);
    QueryType(Request request = Request::balance, QObject *parent = nullptr);

    QString toString();
    int toInt();
    QueryType::Request& getRequest();

    ~QueryType() noexcept = default;

private:
    Request m_request;

};


extern template int EnumToInt(QueryType queryType);
extern template QString EnumToString(QueryType queryType);



#endif // QUERYTYPE_H

