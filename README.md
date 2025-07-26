# Safer memory allocation in C
A set of macro functions which provide a safer memory allocation in C.

<h2> Examples </h2>

* Example A:

<pre>
<code class="language-c">
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include "new.h"

int main()
{
    int* integer = new(int);

    *integer = 10000;

    printf("*integer = %i\n", *integer);

    delete(integer);
    
    return EXIT_SUCCESS;
}
</code>
</pre>

* Example B:

<pre>
<code class="language-c">
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include "new.h"

int main()
{
    const char** strings = new_block(const char*, 3);

    strings[0] = "Hello";
    strings[1] = "world";
    strings[2] = "2025";

    printf("strings: %s %s %s\n", strings[0], strings[1], strings[2]);

    delete(strings);
    
    return EXIT_SUCCESS;
}
</code>
</pre>

* Example C:

<pre>
<code class="language-c">
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include "new.h"

typedef struct point
{
    int x, y;
}point;

int main()
{
    point* points = new_block(point, 2);

    points[0] = (point){1, 1};
    points[1] = (point){2, 2};

    printf("points: {{%i, %i}, {%i, %i}}\n", points[0].x, points[0].y, points[1].x, points[1].y);

    delete(points);
    
    return EXIT_SUCCESS;
}
</code>
</pre>
