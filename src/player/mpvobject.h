#ifndef MPVOBJECT_H
#define MPVOBJECT_H

#include <vector>
#include <memory>

#include <QtQuick/QQuickFramebufferObject>

#include <mpv/client.h>
#include <mpv/render_gl.h>
#include <mpv/qthelper.hpp>

class MpvRenderer;

class MpvObject : public QQuickFramebufferObject
{
    Q_OBJECT

    mpv_handle *mpv;
    mpv_render_context *mpv_gl;
    std::vector<std::unique_ptr<QJSValue>> callbacks;

    friend class MpvRenderer;

public:
    static void on_update(void *ctx);

    MpvObject(QQuickItem * parent = 0);
    virtual ~MpvObject();
    virtual Renderer *createRenderer() const;

    Q_INVOKABLE QVariant getProperty(const QString &name);

public slots:
    void command(const QVariant& params);
    void setProperty(const QString& name, const QVariant& value);
    void setOption(const QString& name, const QVariant& value);
    bool observeProperty(const QString& name, const QJSValue& callback);
    bool unobserveProperty(const QJSValue& callback);

signals:
    void onUpdate();

private slots:
    void doUpdate();

private:
    qint64 time;
    bool event(QEvent *event);
};

#endif // MPVOBJECT_H
