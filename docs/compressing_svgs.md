# How to compress SVGs files

## Installation of `svgo`

```
npm install -g svgo
```

## Using the tool

First please go to the folder which contains SVGs and make a copy from the files if it is necessary.

Running the following will converts the files inside the current folder.

```
for d in `ls -1 *.svg`; do svgo $d; done
```

