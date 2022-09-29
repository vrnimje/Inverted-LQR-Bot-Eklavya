# Linear Algebra

**Table of Contents:**

1. [Vectors](#1-vectors)
1. [Linear Combinations, span and basis of vectors](#2-linear-combinations-span-and-basis-of-vectors)
1. [Linear transformations and matrices](#3-linear-transformations-and-matrices)
1. [Matrix Multiplication as composition](#4-matrix-multiplication-as-composition)
1. [Determinant](#5-determinant)
1. [System of linear equations](#6-system-of-linear-equations)
1. [Inverse Matrices](#7-inverse-matrices)
1. [Rank](#8-rank)
1. [Non Square Matrices](#9-non-square-matrices)
1. [Dot Product](#10-dot-product)
1. [Cross Product](#11-cross-product)
1. [Change of Basis](#12-change-of-basis)
1. [Eigenvectors and eigenvalues](#13-eigenvectors-and-eigenvalues)
1. [Abstract Vector Spaces](#14-abstract-vector-spaces)
---

## 1. Vectors

    Vectors are entities having both magnitude and direction. These can be represented by ordered list of numbers.
<img src="https://miro.medium.com/max/404/1*VFPyMYJNzvyKAwljZhTEiA.png" alt="Vectors" width="300"/>

    Vector Addition
<img src="https://www.alpharithms.com/wp-content/uploads/557/vector-matrix-addition-illustration.jpg" alt="vector addition" width="300"/>


    Scalar Product
<img src="https://miro.medium.com/max/1400/1*gf3HdrkDBi6Dch_XxVuYvA.png" alt="scalar product" width="300"/>


---

## 2. Linear Combinations, span and basis of vectors

    If you take a set of matrices, you multiply each of them by a scalar, and you add together all the products thus obtained, then you obtain a linear combination.

    All the matrices involved in a linear combination need to have the same dimension (otherwise matrix addition would not be possible).
<img src="https://d2vlcm61l7u1fs.cloudfront.net/media%2Fd0c%2Fd0c5025b-ab90-4c34-aa25-1783cc30f1e6%2Fimage" alt="Linear Combination" width="300"/>

    The span of a set of vectors is the set of all linear combinations of the vectors
    For example, if A and B are concurrent and non-collinear vectors of same dimension then, span of their linear combinations will be complete plane on which they lie.
    If A and B are collinear then the span becomes a line.

    Consider linear combination xA + yB + zC, where A, B and C are vectors and x, y, z are scalar variables. If one of these vectors lies on the span of other two then it is linearly dependent. Then span will be plane formed by those two vectors.

    If no vector lies on span of other two vectors, then they all are linearly independent vectors.

    We can write a vector in form A = ai + bj + ck, where i, j and k are basis of space i.e they are linearly independent vectors which span the full space.
---

## 3. Linear transformations and matrices

    Transformations change the landing position of input vector.
    Linear transformations are those in which origin is fixed and lines remain parallel and evenly spaced.
<img src="https://www.geogebra.org/resource/TSQk4yCY/jaJdMZXFpVdsltLe/material-TSQk4yCY.png" alt="Example of Linear transformation" width="400"/>

---

## 4. Matrix Multiplication as composition

    In geometric terms, it is combined effect caused by ordered transformation.
<img src="https://miro.medium.com/max/1126/0*Xqu2NHTqR9a4lBEs.png" alt="Matrix multiplication" width="400"/>


    It is associative but not cummulative. Meanining
    A(BC) = (AB)C, but
    ABC != BAC

---

## 5. Determinant
    Determinant is scale by which any area(in case of 2D) or volume(in case of 3D)changes after transformation.
    Negative determinant signifies that the orientation of plane has been reveresed.
<img src="https://i.ytimg.com/vi/CcbyMH3Noow/maxresdefault.jpg" alt="Determinant" width="400"/>


---

## 6. System of linear equations

    A system of linear equations is a collection of one or more linear equations involving the same variables.
<img src="https://cf2.ppt-online.org/files2/slide/7/7tnIal2HfwUWERMdCBJNAecT31xLYDoOmizuXg/slide-14.jpg" alt="Representing SLE in matrix" width="400"/>

---

## 7. Inverse matrices

    Inverse of a matrix is a matrix which reverses the transformations caused due to matrix.
<img src="https://slidetodoc.com/presentation_image_h/cbcfcd914cb1e9e4c42536acab1b005b/image-12.jpg" alt="Inverse matrix" width="400"/>


---

## 8. Rank
    Rank is the number of dimensions in output of transofrmation. If rank is equal to columns in matrix, then it is called full rank.
    when rank is less than number of columns, a set of vectors will fall to origin. This set of vectors is called "Null Space" or "Kernel".

---

## 9. Non square matrices
    Non square matrices can change the number of dimensions after transformation. For example a 3x2 matrix will transform 3D space to a 2D space.
<img src="https://notesbylex.com/_media/nonsquare-matrices-cover.png" alt="transformation due to Non square matrix" width="400"/>

---

## 10. Dot product
    Dot product is the multiplication of a length of one vector and length of projection of another vector on it.
<img src="https://cdn1.byjus.com/wp-content/uploads/2018/11/maths/2016/06/02115120/Dot-Product-Of-Vectors.jpg" alt="Geometric interpretetion of Dot product" width="400"/>


    Mathematically dot product of two vectors can be given as follows
<img src="https://media5.datahacker.rs/2020/04/Picture27-1024x386.jpg" alt="Dot Product" width="300"/>

---

## 11. Cross Product
    Cross product is the magnitude of the area of parallelogram formed by two vectors. It can also be represented as determinant of the matrix formed by the two vectors. Similar to determinant, the negative sign of cross product signifies that the orientation was fliped during transformation.

<img src = "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTUZ_-YLfBtJYWxUQy4sYt9sSlUyz74LH1gWcXY8oTk3KxgAhxWB-N62SBL-xlf1PDbUDE&usqp=CAU" alt = "Cross Product" width = "300">  <img src = "https://i.ytimg.com/vi/pWbOisq1MJU/maxresdefault.jpg" alt = "Cross Product" width = "500">

---

## 12. Change of basis
    Change of basis is a technique applied to finite-dimensional vector spaces in order to rewrite vectors in terms of a different set of basis elements. 
<img src = "https://i.stack.imgur.com/1bCjE.png" alt = "Change of Basis" width = "500"> 

---

## 13. Eigenvectors and eigenvalues
    During linear transformation vectors get knocked off span. But some vectors remain on their own span. These vectors are known as Eigenvectors of that transformation.
    Eigenvalue is factor by which the eigenvectors get streched or squished during transformation.
    For a 3D space, eigenvector is the axis of rotation during transformation.
<img src = "https://www.sharetechnote.com/image/EngMath_Matrix_Eigen_Eq_02.PNG" alt = "Eigenvector" width = "300"> <img src = "https://www.wikihow.com/images/thumb/f/fd/Find-Eigenvalues-and-Eigenvectors-Step-2.jpg/v4-460px-Find-Eigenvalues-and-Eigenvectors-Step-2.jpg.webp" alt = "Eigenvector" width = "400">

    When the basis of space also become eigenvectors, then the corresponding transformation matrix becomes a diagonal matrix, where the diagonal values are eigenvalues.
---

## 14. Abstract Vector spaces
    Any form of data can be represented as vector as long as it follows the rules for vector adding and scaling (Axioms). All the concepts of linear algebra can be applied to such abstract vector spaces.
<img src = "https://tomcircle.files.wordpress.com/2016/12/20161226_032322.png" alt = "Axioms" width = "400"> 


   