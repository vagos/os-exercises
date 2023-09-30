.PHONY: clean watch all

# PDFS=$(shell find . -name "*.tex" | sed s/.tex/.pdf/)
PDFS=build/main.pdf

all: $(PDFS)

build/%.pdf: %.tex assets/drivers.png assets/mem-map.png
	mkidr -p build
	xelatex -output-directory=build $*.tex

assets/%.png: assets/%.puml
	plantuml assets/$*.puml

clean:
	rm *.pdf

watch:
	find . -not -path "./build" | entr make
