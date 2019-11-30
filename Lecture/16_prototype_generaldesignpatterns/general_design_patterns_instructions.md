- Work in groups of 1 - 3.
- Name : Deanne A. Oceane A. Musaab A.
- Design patterns notes:
  - [Singleton](../13_singleton)
  - [Flyweight/Iterator](../14_flyweight_iterator)
  - [Iterator/Factory](../15_factory)
  - Prototype (in this directory)
  - Also check out: [resources document](../../resources.md)

1. Pick a language other than c++ that you have experience working with. (Note: Felix doesn't want to see *only* python examples, so if you are comfortable using a language other than python/c++, consider choosing that one).

-JAVA
-python

2. Pick a design pattern out of: Singleton, Flyweight, Iterator, Factory, and Prototype.

SINGLETON
FACTORY

3. Describe how you would implement your chosen design pattern in your chosen language. Remember that these are object-oriented design patterns so you should be considering either an object-oriented language or an object-oriented paradigm for using a language that is not inherently object oriented. Include small code examples as appropriate.

This is the same as c++ except our copy constructor isn't deleted it's not implemented.

public class Lecture{
   public static Lecture getInstance(){}
   private Lecture(Lecture one){}
   private Lecture(){}
}

class LectureFactory():
  def GetLecture():
    l = Lecture()
    l.name_ = "name"
    l.title_ = "title"
    l.professor_ = "prof"
    return l

4. Repeat steps 2 & 3 for a second design pattern.

Turn in your answers to questions 1 - 4 as either a .md (markdown), .txt (plain text), or .pdf document on Canvas. Make sure to format your answers so that they are easy to read. If you worked in a group, make a comment on your submission including the names of all group members.
