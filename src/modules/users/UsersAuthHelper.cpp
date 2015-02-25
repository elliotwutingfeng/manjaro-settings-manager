#include "UsersAuthHelper.h"

#include <QtCore/QProcess>
#include <QDebug>

ActionReply UsersAuthHelper::add(const QVariantMap& args)
{
    QProcess *useradd = new QProcess();
    useradd->start("/usr/bin/useradd", args["arguments"].toStringList());
    connect(useradd, &QProcess::readyRead,
            [=] ()
    {
        QString data = QString::fromUtf8(useradd->readAll()).trimmed();
        if (!data.isEmpty()) {
            QVariantMap map;
            map.insert(QLatin1String("Data"), data);
            HelperSupport::progressStep(map);
        }
    });
    if (!useradd->waitForStarted(5000)) {
        return ActionReply::HelperErrorReply();
    }

    if (!useradd->waitForFinished(15000)) {
        return ActionReply::HelperErrorReply();
    }

    if (useradd->exitCode() != QProcess::NormalExit) {
        return ActionReply::HelperErrorReply();
    }

    return ActionReply::SuccessReply();
}

ActionReply UsersAuthHelper::remove(const QVariantMap& args)
{
    return ActionReply::SuccessReply();
}

ActionReply UsersAuthHelper::changepassword(const QVariantMap &args)
{
    QProcess *passwd = new QProcess();
    passwd->start("/usr/bin/passwd", args["arguments"].toStringList());

    connect(passwd, &QProcess::readyRead,
            [=] ()
    {
        QString data = QString::fromUtf8(passwd->readAll()).trimmed();
        if (!data.isEmpty()) {
            QVariantMap map;
            map.insert(QLatin1String("Data"), data);
            HelperSupport::progressStep(map);
        }
    });

    if (!passwd->waitForStarted(5000)) {
        return ActionReply::HelperErrorReply();
    }

    for (QString arg : args["writeArgs"].toStringList()) {
        qDebug() << arg;
        passwd->write(QString(arg + "\n").toUtf8());
    }

    passwd->closeWriteChannel();

    if (!passwd->waitForFinished(15000)) {
        return ActionReply::HelperErrorReply();
    }

    if (passwd->exitCode() != QProcess::NormalExit) {
        return ActionReply::HelperErrorReply();
    }

    return ActionReply::SuccessReply();
}

ActionReply UsersAuthHelper::changeaccounttype(const QVariantMap &args)
{
    return ActionReply::SuccessReply();
}

ActionReply UsersAuthHelper::changeimage(const QVariantMap &args)
{
    return ActionReply::SuccessReply();
}

KAUTH_HELPER_MAIN("org.manjaro.msm.users", UsersAuthHelper)
#include "moc_UsersAuthHelper.cpp"