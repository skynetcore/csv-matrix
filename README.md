# csv-matrix
provides simple interfaces for reading, updating and writing values to a csv file with M rows and N columns treating it like a matrix.
The tool can be used to update a cell at a time or an entire row at a time. the tool can be used for report generation, analytics and data modeling

## build
```bashscript
mkdir build
cmake ..
make
```

## install
```
make install
```

## how it works
the tool can be used to create, update a CSV file of M rows and N columns
```
Syntax for using the tool is as follows 
[./csv-matrix] [create/update] [--filename] [--size]/[[--i][--j][--value]], [--row][--values]
```

## examples
the following examples shows the simplicity of csv-matrix tool
#### creating a csv file of 4 rows and 5 columns
```
  ./csv-matrix  create --filename=matrix.csv --size=4,5
```
  
#### updating an existing csv file that was created using csv-matrix tool
```
direct cell updation at position i=1, j=4
 
  ./csv-matrix  update --filename=matrix.csv --i=1 --j=4 value=0.987
 
entire row updation at position 5
 
  ./csv-matrix  update --filename=matrix.csv --row=5 --values=92.1,34,4,57.4,27,4
```
