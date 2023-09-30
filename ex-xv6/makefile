.PHONY: clean watch all

all: system-call scheduler

system-call: build/system-call.pdf assets/syscall/drivers.png

scheduler: build/scheduler.pdf

build/%.pdf: %.tex 
	mkdir -p build
	latexmk --pdflatex='xelatex %O %S' -pdf -g $< -outdir=build --shell-escape


assets/%.png: assets/%.puml
	plantuml assets/$*.puml

clean:
	latexmk -pdflatex='xelatex %O %S' -pdf main.tex -outdir=build -CA

watch:
	find . -not -path "./build" | entr make -B
