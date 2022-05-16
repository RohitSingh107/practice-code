FROM archlinux:latest

RUN pacman -Syyuu --noconfirm
RUN pacman -S --needed discord-canary xorg-xauth neofetch --noconfirm


EXPOSE 8887
CMD neofetch
