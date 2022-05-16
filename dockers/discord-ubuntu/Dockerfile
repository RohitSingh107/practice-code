FROM ubuntu:latest
RUN apt-get -y update
RUN apt-get -y install xauth
RUN apt-get -y install neofetch
RUN apt-get -y install gdebi-core wget
RUN mkdir /discord
RUN wget -O /discord/discord.deb "https://discordapp.com/api/download?platform=linux&format=deb"
RUN gdebi /discord/discord.deb

EXPOSE 8887
CMD discord
