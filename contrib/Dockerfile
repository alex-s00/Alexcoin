FROM amd64/ubuntu:20.04 AS base

#If you found this docker image helpful please donate ALEX to the maintainer
LABEL maintainer="RV9zdNeUTQUToZUcRp9uNF8gwH5LzDFtan"

EXPOSE 8766/tcp
EXPOSE 8767/tcp

ENV DEBIAN_FRONTEND=noninteractive

#Install runtime dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash wget net-tools libminiupnpc17 \
	libevent-2.1 libevent-pthreads-2.1 \
	libboost-system1.71 libboost-filesystem1.71 libboost-chrono1.71 \
	libboost-program-options1.71 libboost-thread1.71 \
	libzmq5 && \
	apt-get clean

FROM base AS build

#Install build dependencies
RUN apt-get update && \
	apt-get install -y --no-install-recommends \
	bash net-tools build-essential libtool autotools-dev automake \
	pkg-config libssl-dev libevent-dev bsdmainutils python3 \
	libboost-system1.71-dev libboost-filesystem1.71-dev libboost-chrono1.71-dev \
	libboost-program-options1.71-dev libboost-test1.71-dev libboost-thread1.71-dev \
	libzmq3-dev libminiupnpc-dev && \
	apt-get clean

#Copy source dir
COPY . /home/alex/build/Alexcoin/
WORKDIR /home/alex/build/Alexcoin

#build db4 from source
WORKDIR /home/alex/build/Alexcoin/contrib
RUN ./install_db4.sh ../../

# build Alexcore
WORKDIR /home/alex/build/Alexcoin
RUN ./autogen.sh && ./configure --disable-tests BDB_LIBS="-L/home/alex/build/db4/lib -ldb_cxx-4.8" BDB_CFLAGS="-I/home/alex/build/db4/include" --with-gui=no  && make -j4

FROM base AS final

#Add our service account user
RUN useradd -ms /bin/bash alex && \
	mkdir /var/lib/alex && \
	chown alex:alex /var/lib/alex && \
	ln -s /var/lib/alex /home/alex/.alex && \
	chown -h alex:alex /home/alex/.alex

VOLUME /var/lib/alex

#Copy the compiled binaries from the build
COPY --from=build /home/alex/build/Alexcoin/src/alexd /usr/local/bin/alexd
COPY --from=build /home/alex/build/Alexcoin/src/alex-cli /usr/local/bin/alex-cli

WORKDIR /home/alex
USER alex

CMD /usr/local/bin/alexd -datadir=/var/lib/alex -printtoconsole -onlynet=ipv4
