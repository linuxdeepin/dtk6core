/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ./dtkcore/src/dbus/org.desktopspec.ConfigManager.Manager.xml -a ./dtkcore/toolGenerate/qdbusxml2cpp/org.desktopspec.ConfigManager.ManagerAdaptor -i ./dtkcore/toolGenerate/qdbusxml2cpp/org.desktopspec.ConfigManager.Manager.h
 *
 * qdbusxml2cpp is Copyright (C) 2017 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef ORG_DESKTOPSPEC_CONFIGMANAGER_MANAGERADAPTOR_H
#define ORG_DESKTOPSPEC_CONFIGMANAGER_MANAGERADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "./dtkcore/toolGenerate/qdbusxml2cpp/org.desktopspec.ConfigManager.Manager.h"
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface org.desktopspec.ConfigManager.Manager
 */
class ManagerAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.desktopspec.ConfigManager.Manager")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.desktopspec.ConfigManager.Manager\">\n"
"    <property access=\"read\" type=\"s\" name=\"version\"/>\n"
"    <property access=\"read\" type=\"as\" name=\"keyList\"/>\n"
"    <method name=\"value\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"out\" type=\"v\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"isDefaultValue\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"out\" type=\"b\" name=\"isDefaultValue\"/>\n"
"    </method>\n"
"    <method name=\"setValue\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"in\" type=\"v\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"reset\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"    </method>\n"
"    <method name=\"name\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"language\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"name\"/>\n"
"    </method>\n"
"    <method name=\"description\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"language\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"description\"/>\n"
"    </method>\n"
"    <method name=\"visibility\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"visibility\"/>\n"
"    </method>\n"
"    <method name=\"permissions\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"key\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"permissions\"/>\n"
"    </method>\n"
"    <method name=\"release\"/>\n"
"    <signal name=\"valueChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"key\"/>\n"
"    </signal>\n"
"  </interface>\n"
        "")
public:
    ManagerAdaptor(QObject *parent);
    virtual ~ManagerAdaptor();

public: // PROPERTIES
    Q_PROPERTY(QStringList keyList READ keyList)
    QStringList keyList() const;

    Q_PROPERTY(QString version READ version)
    QString version() const;

public Q_SLOTS: // METHODS
    QString description(const QString &key, const QString &language);
    bool isDefaultValue(const QString &key);
    QString name(const QString &key, const QString &language);
    QString permissions(const QString &key);
    void release();
    void reset(const QString &key);
    void setValue(const QString &key, const QDBusVariant &value);
    QDBusVariant value(const QString &key);
    QString visibility(const QString &key);
Q_SIGNALS: // SIGNALS
    void valueChanged(const QString &key);
};

#endif
