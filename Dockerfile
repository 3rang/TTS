FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    git \
    cmake \
    wget \
    unzip \
    python3 \
    python3-pip \
    python3-venv \
    curl \
    nlohmann-json3-dev \
    vim 


RUN pip install wheel && \
 pip install tensorflow && \
 pip install tensorflow-cpu

RUN  cd /tmp && \
 git clone https://github.com/tensorflow/tensorflow.git && \
 cd /tmp/tensorflow/tensorflow/lite/ && \
 git switch --detach v2.6.0 && \
 cd /tmp/tensorflow/tensorflow/lite/ && \
 mkdir build && cd build && \
 cmake .. && make -j${nproc} && \
 make install 

RUN ./tmp/tensorflow/tensorflow/lite/tools/make/download_dependencies.sh && \
 ./tmp/tensorflow/tensorflow/lite/tools/make/build_lib.sh && \
 cp -r /tmp/tensorflow/tensorflow/lite/tools/make/gen/linux_x86_64/lib/*.a /usr/lib/ && \
 cp -r /tmp/tensorflow/tensorflow /usr/include/ && \
 cp -r /tmp/tensorflow/tensorflow/lite/build/flatbuffers/include/flatbuffers /usr/include/


RUN cd /tmp && \
    git clone https://github.com/3rang/TTS.git && \
    cd TTS && \
    mkdir build && cd build && \
    cmake .. && make -j${nproc} 
    


WORKDIR /tmp


CMD ["bash"]
