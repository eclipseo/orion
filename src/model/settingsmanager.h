#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QObject>
#include <QSettings>
#include "singletonprovider.h"

class SettingsManager : public QObject
{
    QML_SINGLETON
    Q_OBJECT

    Q_PROPERTY(bool alert READ alert WRITE setAlert NOTIFY alertChanged)
    Q_PROPERTY(bool closeToTray READ closeToTray WRITE setCloseToTray NOTIFY closeToTrayChanged)
    Q_PROPERTY(bool multipleInstances READ multipleInstances WRITE setMultipleInstances NOTIFY multipleInstancesChanged)
    Q_PROPERTY(int alertPosition READ alertPosition WRITE setAlertPosition NOTIFY alertPositionChanged)
    Q_PROPERTY(int volumeLevel READ volumeLevel WRITE setVolumeLevel NOTIFY volumeLevelChanged)
    Q_PROPERTY(bool minimizeOnStartup READ minimizeOnStartup WRITE setMinimizeOnStartup NOTIFY minimizeOnStartupChanged)
    Q_PROPERTY(int chatEdge READ chatEdge WRITE setChatEdge NOTIFY chatEdgeChanged)
    Q_PROPERTY(bool offlineNotifications READ offlineNotifications WRITE setOfflineNotifications NOTIFY offlineNotificationsChanged)
    Q_PROPERTY(double textScaleFactor READ textScaleFactor WRITE setTextScaleFactor NOTIFY textScaleFactorChanged)
    Q_PROPERTY(QString opengl READ opengl WRITE setOpengl NOTIFY openglChanged)
    Q_PROPERTY(QString quality READ quality WRITE setQuality NOTIFY qualityChanged)
    Q_PROPERTY(QString decoder READ decoder WRITE setDecoder NOTIFY decoderChanged)
    Q_PROPERTY(QString accessToken READ accessToken WRITE setAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(bool hasAccessToken READ hasAccessToken NOTIFY accessTokenChanged)
    Q_PROPERTY(bool lightTheme READ lightTheme WRITE setLightTheme NOTIFY lightThemeChanged)
    Q_PROPERTY(QString font READ font WRITE setFont NOTIFY fontChanged)
    Q_PROPERTY(bool versionCheckEnabled READ versionCheckEnabled)
    Q_PROPERTY(bool keepOnTop READ keepOnTop WRITE setKeepOnTop NOTIFY keepOnTopChanged)

    bool mAlert;
    bool mCloseToTray;
    bool mMultipleInstances;
    int mAlertPosition;
    int mVolumeLevel;
    bool mMinimizeOnStartup;
    bool mSwapChat;
    bool mOfflineNotifications;
    double mTextScaleFactor;
    QString mOpengl;
    QString mQuality;
    QString mDecoder;
    QString mAccessToken;
    int mChatEdge;
    bool mLightTheme;
    QString mFont;

    bool mHiDpi;
    bool mKeepOnTop;

    explicit SettingsManager(QObject *parent = nullptr);
    static SettingsManager *instance;
public:
    static SettingsManager *getInstance();

    bool alert() const;
    void setAlert(bool alert);

    bool closeToTray() const;
    void setCloseToTray(bool closeToTray);

    bool multipleInstances() const;
    void setMultipleInstances(bool multipleInstances);

    int alertPosition() const;
    void setAlertPosition(int alertPosition);

    int volumeLevel() const;
    void setVolumeLevel(int volumeLevel);

    bool minimizeOnStartup() const;
    void setMinimizeOnStartup(bool minimizeOnStartup);

    int chatEdge() const;
    void setChatEdge(int chatEdge);

    bool offlineNotifications() const;
    void setOfflineNotifications(bool offlineNotifications);

    double textScaleFactor() const;
    void setTextScaleFactor(double textScaleFactor);

    QString opengl() const;
    void setOpengl(const QString &opengl);

    QString quality() const;
    void setQuality(const QString &quality);

    QString decoder() const;
    void setDecoder(const QString &decoder);

    QString accessToken() const;

    void setHiDpi(bool dpi);

    bool lightTheme() const;
    void setLightTheme(bool lightTheme);

    QString font() const;
    void setFont(const QString &font);

    bool versionCheckEnabled();

    bool keepOnTop() const;
    void setKeepOnTop(bool keepOnTop);

signals:
    void alertChanged();
    void closeToTrayChanged();
    void multipleInstancesChanged();
    void alertPositionChanged();
    void volumeLevelChanged();
    void minimizeOnStartupChanged();
    void chatEdgeChanged();
    void offlineNotificationsChanged();
    void textScaleFactorChanged();
    void openglChanged();
    void qualityChanged();
    void decoderChanged();
    void lightThemeChanged();
    void accessTokenChanged(QString accessToken);
    void fontChanged();
    void keepOnTopChanged();

public slots:
    void setAccessToken(const QString accessToken);
    bool hasAccessToken() const;
    void load();

    bool hiDpi() const;
    QString appName() const;
    QString appVersion() const;
    QString appPlayerBackend() const;
    bool isNewerVersion(QString version) const;

private:
    QSettings *settings;
};

#endif // SETTINGSMANAGER_H
