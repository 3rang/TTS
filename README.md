# NAME

## Project Structure
This is the current structure of the project
```shell
├── app                 # C++ based speech engine
│   ├── CMakeLists.txt
│   ├── include         # Top level includes
│   ├── python-tests    # Component Tests in python
│   ├── src             # Source code
│   │   ├── asr         # Automated Speech Recognizer code
│   │   ├── nlu         # Natural Language Understanding code
│   │   ├── spotter     # Keyword Spotting code
│   │   └── tts         # Text to Speech code
│   │   └── aal         # Audio Abstraction Layer code
│   │   └── mercies     # Actual application
│   └── systemd         # Systemd related files
├── Dockerfile
├── docs                # Markdown style documentation
├── explore             # Experiments run in python
│   └── notebooks       # Jupyter Notebooks
├── Jenkinsfile
├── README.md
└── scripts             # Helper scripts
```

# Setup Docker 

```shell

# Create a workspace for your work
mkdir workspace-name
cd workspace-name

# clone the repo.
git clone ssh://git@git.swf.daimler.com:7999/mbient/mercies.git
cd mercies/

# Build the docker container to setup development environment
docker build -f Dockerfile -t tts .
 
# run docker 
docker run -v $PWD:/home/tts/mercies --network host -it tts:latest

```

# Build the Application 

# High Level Arquitecture

## More coming soon..
