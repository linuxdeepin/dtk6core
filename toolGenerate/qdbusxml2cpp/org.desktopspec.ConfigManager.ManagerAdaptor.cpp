/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ./dtkcore/src/dbus/org.desktopspec.ConfigManager.Manager.xml -a ./dtkcore/toolGenerate/qdbusxml2cpp/org.desktopspec.ConfigManager.ManagerAdaptor -i ./dtkcore/toolGenerate/qdbusxml2cpp/org.desktopspec.ConfigManager.Manager.h
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "./dtkcore/toolGenerate/qdbusxml2cpp/org.desktopspec.ConfigManager.ManagerAdaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class ManagerAdaptor
 */

ManagerAdaptor::ManagerAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

ManagerAdaptor::~ManagerAdaptor()
{
    // destructor
}

QStringList ManagerAdaptor::keyList() const
{
    // get the value of property keyList
    return qvariant_cast< QStringList >(parent()->property("keyList"));
}

QString ManagerAdaptor::version() const
{
    // get the value of property version
    return qvariant_cast< QString >(parent()->property("version"));
}

QString ManagerAdaptor::description(const QString &key, const QString &language)
{
    // handle method call org.desktopspec.ConfigManager.Manager.description
    QString description;
    QMetaObject::invokeMethod(parent(), "description", Q_RETURN_ARG(QString, description), Q_ARG(QString, key), Q_ARG(QString, language));
    return description;
}

bool ManagerAdaptor::isDefaultValue(const QString &key)
{
    // handle method call org.desktopspec.ConfigManager.Manager.isDefaultValue
    bool isDefaultValue;
    QMetaObject::invokeMethod(parent(), "isDefaultValue", Q_RETURN_ARG(bool, isDefaultValue), Q_ARG(QString, key));
    return isDefaultValue;
}

QString ManagerAdaptor::name(const QString &key, const QString &language)
{
    // handle method call org.desktopspec.ConfigManager.Manager.name
    QString name;
    QMetaObject::invokeMethod(parent(), "name", Q_RETURN_ARG(QString, name), Q_ARG(QString, key), Q_ARG(QString, language));
    return name;
}

QString ManagerAdaptor::permissions(const QString &key)
{
    // handle method call org.desktopspec.ConfigManager.Manager.permissions
    QString permissions;
    QMetaObject::invokeMethod(parent(), "permissions", Q_RETURN_ARG(QString, permissions), Q_ARG(QString, key));
    return permissions;
}

void ManagerAdaptor::release()
{
    // handle method call org.desktopspec.ConfigManager.Manager.release
    QMetaObject::invokeMethod(parent(), "release");
}

void ManagerAdaptor::reset(const QString &key)
{
    // handle method call org.desktopspec.ConfigManager.Manager.reset
    QMetaObject::invokeMethod(parent(), "reset", Q_ARG(QString, key));
}

void ManagerAdaptor::setValue(const QString &key, const QDBusVariant &value)
{
    // handle method call org.desktopspec.ConfigManager.Manager.setValue
    QMetaObject::invokeMethod(parent(), "setValue", Q_ARG(QString, key), Q_ARG(QDBusVariant, value));
}

QDBusVariant ManagerAdaptor::value(const QString &key)
{
    // handle method call org.desktopspec.ConfigManager.Manager.value
    QDBusVariant value;
    QMetaObject::invokeMethod(parent(), "value", Q_RETURN_ARG(QDBusVariant, value), Q_ARG(QString, key));
    return value;
}

QString ManagerAdaptor::visibility(const QString &key)
{
    // handle method call org.desktopspec.ConfigManager.Manager.visibility
    QString visibility;
    QMetaObject::invokeMethod(parent(), "visibility", Q_RETURN_ARG(QString, visibility), Q_ARG(QString, key));
    return visibility;
}
