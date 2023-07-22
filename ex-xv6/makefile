.PHONY: clean watch all

# PDFS=$(shell find . -name "*.tex" | sed s/.tex/.pdf/)
PDFS=system-call.pdf scheduler.pdf

PDFS := $(addprefix build/,$(PDFS))

all: $(PDFS)

build/%.pdf: %.tex 
	mkdir -p build
	latexmk --pdflatex='xelatex %O %S' -pdf $< -outdir=build --shell-escape

assets/%.png: assets/%.puml
	plantuml assets/$*.puml

clean:
	latexmk -pdflatex='xelatex %O %S' -pdf main.tex -outdir=build -CA

watch:
	find . -not -path "./build" | entr make
