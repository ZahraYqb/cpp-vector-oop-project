<h2>A report on the factors affecting the number of clocks in part 1.3 of the project based on my observation:</h2>
<ul>
  <li>The number of the inserted/removed shape objects:<br>
     The more shape objects, the more clocks will be needed.</li>
  <li>The amount of memory allocated to the data member of the shape class:<br>
      As the amount of memory increases, the number of clocks will be increased.</li>
  <li>The number of existing elements before inserting/removing elements:<br>
      This factor and the number of clocks have a direct relationship as well.</li>
  <li>After a lot of examination, inserting needs more clocks than removing at most of the times, because of a simpler function.  </li>
</ul>

<h2>Comparing T** to T*:</h2>
The number of clocks when inserting or removing elements for the vector of pointers to the shapes (T**) is <mark> significantly lower </mark> than vector of shapes(T*). This shows that as we work with large objects, using pointers can be more efficient in memory management.
