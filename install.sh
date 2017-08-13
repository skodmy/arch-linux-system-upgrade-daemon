cc src/system-upgrade-daemon.c -o /usr/bin/system-upgrade-daemon

cp systemd/system-upgrade-daemon.service /usr/lib/systemd/system

systemctl daemon-reload

