// SPDX-FileCopyrightText: 2021 - 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include <gtest/gtest.h>
#include <QFile>
#include <QLocale>
#include <QTemporaryFile>

#include "log/Logger.h"
#include "log/dloghelper.h"
#include "log/FileAppender.h"
#include "log/ConsoleAppender.h"
#include "log/RollingFileAppender.h"

DCORE_USE_NAMESPACE

class ut_Logger: public testing::Test
{
protected:
    void SetUp() override;
    void TearDown() override;
    QString tmpFileName() {
        Q_ASSERT(m_tmpFile);
        return m_tmpFile->fileName();
    }
    Logger *m_logger = nullptr;
    QTemporaryFile *m_tmpFile = nullptr;
};

void ut_Logger::SetUp()
{
    m_logger = new Logger;
    m_tmpFile = new QTemporaryFile;
    m_tmpFile->open();
}

void ut_Logger::TearDown()
{
    if (m_logger) {
        delete m_logger;
        m_logger = nullptr;
    }
    m_tmpFile->close();
    delete m_tmpFile;
}

TEST_F(ut_Logger, testLevelToString)
{
    QString trace = Logger::levelToString(Logger::Trace);
    ASSERT_EQ(trace, "Trace");
    QString debug = Logger::levelToString(Logger::Debug);
    ASSERT_EQ(debug, "Debug");
    QString info = Logger::levelToString(Logger::Info);
    ASSERT_EQ(info, "Info");
    QString warning = Logger::levelToString(Logger::Warning);
    ASSERT_EQ(warning, "Warning");
    QString error = Logger::levelToString(Logger::Error);
    ASSERT_EQ(error, "Error");
    QString fatal = Logger::levelToString(Logger::Fatal);
    ASSERT_EQ(fatal, "Fatal");
}

TEST_F(ut_Logger, testLevelFromString)
{
    Logger::LogLevel trace = Logger::levelFromString("Trace");
    ASSERT_EQ(trace, Logger::Trace);
    Logger::LogLevel debug = Logger::levelFromString("Debug");
    ASSERT_EQ(debug, Logger::Debug);
    Logger::LogLevel info = Logger::levelFromString("Info");
    ASSERT_EQ(info, Logger::Info);
    Logger::LogLevel warning = Logger::levelFromString("Warning");
    ASSERT_EQ(warning, Logger::Warning);
    Logger::LogLevel error = Logger::levelFromString("Error");
    ASSERT_EQ(error, Logger::Error);
    Logger::LogLevel fatal = Logger::levelFromString("Fatal");
    ASSERT_EQ(fatal, Logger::Fatal);
}

TEST_F(ut_Logger, testGlobalInstance)
{
    ASSERT_TRUE(Logger::globalInstance());
}

TEST_F(ut_Logger, testRegisterAppender)
{
    Logger* gLogger = Logger::globalInstance();
    FileAppender *fileAppener = new FileAppender(tmpFileName());
    if (fileAppener->detailsLevel() > Logger::Trace)
        fileAppener->setDetailsLevel(Logger::Trace);
    gLogger->registerAppender(fileAppener);
    ASSERT_TRUE(fileAppener->size() == 0);
    dInfo("testRegisterAppender");
    ASSERT_TRUE(fileAppener->size() != 0);

    ConsoleAppender *consoleAppener = new ConsoleAppender();
    if (consoleAppener->detailsLevel() > Logger::Trace)
        consoleAppener->setDetailsLevel(Logger::Trace);
    gLogger->registerAppender(consoleAppener);
    consoleAppener->ignoreEnvironmentPattern(false);
    QString format = consoleAppener->format();
    consoleAppener->setFormat("[%{file}: %{line} %{type:-7}] <%{function}> %{message}\n");
    dTrace("testRegisterAppender");

    RollingFileAppender *rollingFileAppender = new RollingFileAppender("/tmp/rollLog");
    if (rollingFileAppender->detailsLevel() > Logger::Trace)
        rollingFileAppender->setDetailsLevel(Logger::Trace);
    gLogger->registerAppender(rollingFileAppender);
    rollingFileAppender->setLogFilesLimit(2);
    ASSERT_TRUE(rollingFileAppender->logFilesLimit() == 2);
    rollingFileAppender->setDatePattern(RollingFileAppender::MinutelyRollover);
    ASSERT_TRUE(rollingFileAppender->datePattern() == RollingFileAppender::MinutelyRollover);
    dTrace("testRegisterAppender");
    rollingFileAppender->setDatePattern(RollingFileAppender::HourlyRollover);
    ASSERT_TRUE(rollingFileAppender->datePattern() == RollingFileAppender::HourlyRollover);
    dTrace("testRegisterAppender");
    rollingFileAppender->setDatePattern(RollingFileAppender::HalfDailyRollover);
    ASSERT_TRUE(rollingFileAppender->datePattern() == RollingFileAppender::HalfDailyRollover);
    dTrace("testRegisterAppender");
}

TEST_F(ut_Logger, testRegisterCategoryAppender)
{
    qInfo() << "tmpFileName()" << tmpFileName();
    Logger* gLogger = Logger::globalInstance();
    FileAppender *fileAppener = new FileAppender(tmpFileName());
    gLogger->registerCategoryAppender("testRegisterCategoryAppender", fileAppener);
    if (fileAppener->detailsLevel() > Logger::Trace)
        fileAppener->setDetailsLevel(Logger::Trace);
    ASSERT_TRUE(fileAppener->size() == 0);
    dCDebug("testRegisterCategoryAppender") << "testRegisterCategoryAppender";
    ASSERT_TRUE(fileAppener->size() != 0);
}

TEST_F(ut_Logger, testLogToGlobalInstance)
{
    Logger* gLogger = Logger::globalInstance();
    FileAppender *fileAppener = new FileAppender(tmpFileName());
    if (fileAppener->detailsLevel() > Logger::Trace)
        fileAppener->setDetailsLevel(Logger::Trace);
    gLogger->registerAppender(fileAppener);

    ASSERT_TRUE(fileAppener->size() == 0);
    dTrace("testRegisterAppender");
    ASSERT_TRUE(fileAppener->size() != 0);
}

TEST_F(ut_Logger, testSetDefaultCategory)
{
    m_logger->setDefaultCategory("testSetDefaultCategory");
    ASSERT_EQ(m_logger->defaultCategory(), "testSetDefaultCategory");
}

TEST_F(ut_Logger, testDefaultCategory)
{
    ASSERT_EQ(m_logger->defaultCategory(), "");
}
