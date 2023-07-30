.PHONY: clean watch

PDFS=$(shell find . -name "*.md" | sed s/.md/.pdf/)
PDFS := $(addprefix build/,$(PDFS))

all: $(PDFS)

build/%.pdf: %.md
	pandoc --citeproc -t latex -o $*.pdf --pdf-engine=xelatex -V mainfont="Libertinus Sans" -V lang=el \
	--include-in-header disable_float.tex -f markdown $*.md
	mv $*.pdf build

clean:
	rm *.pdf

watch:
	find . -name "*.md" | entr make
