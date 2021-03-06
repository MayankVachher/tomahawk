/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2015, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QObject>
#include <QDateTime>
#include <QUrl>

#include "DownloadJob.h"

class DownloadManager : public QObject
{
Q_OBJECT

public:
    enum DownloadManagerState { None, Running, Paused, Waiting };
    static DownloadManager* instance();

    DownloadManager();
    ~DownloadManager();

    DownloadManagerState state() const;

    QList<downloadjob_ptr> jobs( DownloadJob::TrackState state = DownloadJob::Any ) const;
    bool containsJob( const downloadjob_ptr& job ) const;
    downloadjob_ptr currentJob() const;

public slots:
    bool addJob( const downloadjob_ptr& job );
    bool removeJob( const downloadjob_ptr& job );
    void checkJobs();

    void pause();
    void resume();

    void resumeJobs();

signals:
    void jobAdded( const downloadjob_ptr& job );
    void jobRemoved( const downloadjob_ptr& job );

    void stateChanged( DownloadManagerState newState, DownloadManagerState oldState );

private slots:

private:
    QList< downloadjob_ptr > m_jobs;
    bool m_globalState;

    static DownloadManager* s_instance;
};

#endif // DOWNLOADMANAGER_H
