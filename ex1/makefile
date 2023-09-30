.PHONY: clean watch

PDFS=build/main.pdf

all: $(PDFS)

build/%.pdf: %.tex
	mkidr -p build
	xelatex -output-directory=build $*.tex

clean:
	rm *.pdf

watch:
	find . -name "*.tex" | entr make
