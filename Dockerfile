FROM amd64/ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y \
    build-essential \
    git \
    qemu-system-x86

RUN git clone https://github.com/vagos/xv6-x86.git xv6
