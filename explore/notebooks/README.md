# This notebook provides a basic tensorflow based demonstration of tts features.


## Download models

* fastspeech2 model
    
```shell
curl -u<USERNAME>:<PASSWORD> -O "https://artifact.swf.daimler.com/mbient-bin-delivery/speech/mercies/tts/fastspeech2_quan.tflite"
```
* vocoder model

```shell
curl -u<USERNAME>:<PASSWORD> -O "https://artifact.swf.daimler.com/mbient-bin-delivery/speech/mercies/tts/mb_melgan.tflite"
```

* mel-vocoder yaml config file 

```shell
curl -u<USERNAME>:<PASSWORD> -O "https://artifact.swf.daimler.com/mbient-bin-delivery/speech/mercies/tts/melgan.v1.yaml"
```


* ljspeech database json file 

```shell
curl -u<USERNAME>:<PASSWORD> -O "https://artifact.swf.daimler.com/mbient-bin-delivery/speech/mercies/tts/ljspeech_mapper.json"
```



**NOTE** :  **USERNAME** and **PASSWORD** of artifactory

**NOTE** :  model should be saved in the same folder (/mercies/explore/notebooks).

## Enviroment setup   

### Requirement 

| Tool| Description | command |
|:---:|:-----------:|:-------------------:|
| [poetry](https://python-poetry.org/docs/) | tool for dependency management and packaging in Python |``` pip3 install poetry```|



## Run the jupyter notebook 

Now, we are ready to use the notebook 

```shell
#Go to the notbook folder
cd mercies/explore/notebooks
# update poetry (it install all dependency)
 poetry update
#start shell 
 poetry shell
#start notebook 
 jupyter notebook --allow-root

```
after runing it will show the URL to open notebook in web-browser 

![URL](docs/images/url.png)

