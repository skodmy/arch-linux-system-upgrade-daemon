# arch-linux-system-upgrade-daemon
Arch Linux system upgrade daemon.

## Prerequisites
For running installation you need to have on your machine bash, gcc and root privileges.

## Installation
From bash run:
	
	sudo ./install.sh

## Usage
For daemon being running you need to have pacman, also systemd will be useful for automation some tasks.

For performing the next commands you need to have a root privileges.

For a status check run in terminal:

	systemctl status system-upgrade-daemon

For starting a daemon run in terminal:

	systemctl start system-upgrade-daemon

For stopping:

	systemctl stop system-upgrade-daemon

For enabling a service run in bash:

	systemctl enable system-upgrade-daemon

For disabling:
	
	systemctl disable system-upgrade-daemon

## Uninstallation
First run in terminal:
	
	systemctl status system-upgrade-daemon

If you see active on status line then run:
	
	systemctl stop system-upgrade-daemon

If you earlier have enabled service then you need to run:

	systemctl disable system-upgrade-daemon

At last, for uninstalling run:
	
	sudo ./uninstall.sh

## Future prospects
This software will packaged and uploaded to one of Arch Linux repositories for managing it easily with pacman.
