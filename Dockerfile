FROM ubuntu:18.04

RUN pip3 install wheel && \
 pip3 install tensorflow && \
 pip3 install tensorflow-cpu

RUN  cd /tmp && \
 git clone https://github.com/tensorflow/tensorflow.git && \
 cd /tmp/tensorflow/tensorflow/lite/ && \
 mkdir build && cd build && \
 cmake .. && make -j${nproc} && \
 make install 

RUN ./tmp/tensorflow/tensorflow/lite/tools/make/download_dependencies.sh && \
 ./tmp/tensorflow/tensorflow/lite/tools/make/build_lib.sh && \
 cp -r /tmp/tensorflow/tensorflow/lite/tools/make/gen/linux_x86_64/lib/*.a /usr/lib/ && \
 cp -r /tmp/tensorflow/tensorflow /usr/include/ && \
 cp -r /tmp/tensorflow/tensorflow/lite/build/flatbuffers/include/flatbuffers /usr/include/

ARG userid=1000
ARG groupid=1000
ARG username=dev
ARG groupname=dev

RUN groupadd -o -g ${groupid} ${groupname} && useradd -o --no-log-init -m -u ${userid} -g ${groupname} ${username}

USER ${username}

CMD ["/bin/ash"]
