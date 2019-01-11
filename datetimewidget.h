/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>

class DatetimeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DatetimeWidget(QWidget *parent = nullptr);

    bool is24HourFormat() const { return m_24HourFormat; }
    bool displayDate() const { return m_displayDate; }

signals:
    void requestUpdateGeometry() const;

public slots:
    void set24HourFormat(const bool value);
    void setDisplayDate(const bool value);

protected:
    const QString format();

private:
    QSize sizeHint() const;
    void resizeEvent(QResizeEvent *e);
    void paintEvent(QPaintEvent *e);
    void afterSetting();

    const QPixmap loadSvg(const QString &fileName, const QSize size);

private:
    QPixmap m_cachedIcon;
    QString m_cachedTime;
    bool m_24HourFormat;
    bool m_displayDate;
};

#endif // DATETIMEWIDGET_H
