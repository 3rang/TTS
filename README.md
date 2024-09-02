# Deep Learning Based Text-to-Speech (TTS) for Embedded Linux Platform

## Project Structure
This is the current structure of the project
```shell
mainApp
├── CMakeLists.txt		
├── Dockerfile			# Docker 
├── docs			# docs and images
│   └── images
│       └── url.png
├── explore			# Experimental juypter notebook for tts 
│   └── notebooks
│       └── tts_tflite.ipynb
├── LICENSE
├── model			# tflite models
├── README.md
├── scripts 			# Helper Scripts
└── src				# Source Code
    ├── audioplayer 		# Pulse Audio based Audio player (W.I.P)
    ├── main			# Actual Start of Application 
    └── tts			# Text-to-Speech Application based on tflite

```

# Setup Docker 

```shell

# Create a workspace for your work
mkdir workspace-name
cd workspace-name

# clone the repo.
git clone git@github.com:3rang/TTS.git
cd TTS/

# Build the docker container to set the development environment
docker build -f Dockerfile -t tts .
 
# run docker 
docker run -v $PWD:/home/mnt/ --network host -it tts:latest

```


# Build and Run application in Docker 

```shell

root@ip-10-XX-XX80-152:cd /tmp/TTS/build

root@ip-10-XX-XX80-152:/tmp/TTS/build# ./mainApp 
Error : json_path ,  text , model_path , vocoder model_path

# Run application 

root@ip-10-XX-XX80-152:/tmp/TTS/build#./mainApp ../model/ljspeech_mapper.json " Hello there , I am TTS " ../model/fastspeech2_quan.tflite ../model/mel.tflite 
TTSModel melgenPath
TTSModel vocoderfile

after completion of this application, it  will generate a .wav file " example.wav ".

# COPY to the host system Use a Shared Volume

cp example.wav /mnt (/mnt is a shared volume folder between docker and host)

exit this and you can have a .wav file in the host and use 'aplay' or any other audio utility to play the .wav file.

```





