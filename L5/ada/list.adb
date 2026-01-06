with Ada.Text_IO; use Ada.Text_IO;

package body list is
    function isEmpty (l : ListT) return Boolean is
    begin
        return l.first = null;
    end isEmpty;

    function Pop (l : in out ListT) return Integer is
        n : NodePtr := l.first;
        e : Integer := n.elem;
    begin
        l.first := n.next;
        if l.first = null then -- last element
            l.last := null;
        end if;
        Free (n);
        l.length := l.length - 1;
        return e;
    end Pop;

    procedure Push (l : in out ListT; e : Integer) is
        n : NodePtr := new Node;
    begin
        n.elem := e;
        n.next := l.first;
        l.first := n;
        if l.last = null then -- first element
            l.last := n;
        end if;
        l.length := l.length + 1;
    end Push;

    procedure Append (l : in out ListT; e : Integer) is
        n : NodePtr := new Node;
    begin
        n.elem := e;
        if l.first = null then -- first element
            l.first := n;
        else
            l.last.next := n;
        end if;
        l.last := n;
        l.length := l.length + 1;
    end Append;

    function Get (l : ListT; i : Integer) return Integer is
        n : NodePtr := l.first;
        it : Integer := 1;
    begin
        while it < i loop
            n := n.next;
            it := it + 1;
        end loop;
        return n.elem;
    end Get;

    procedure Delete (l : in out ListT; i : Integer) is
        n : NodePtr := l.first;
        del : NodePtr := l.first;
        it : Integer := 1;
    begin
        if i = 1 then
            it := Pop(l);
            return;
        end if;
        while it < i - 1 loop
            del := del.next;
            it := it + 1;
        end loop;
        n := del.next;
        del.next := n.next;
        free(n);
        l.length := l.length - 1;
    end Delete;


    procedure Put (l : in out ListT; i : Integer; e : Integer) is
        n : NodePtr := l.first;
        it : Integer := 1;
    begin
        while it < i loop
            n := n.next;
            it := it + 1;
        end loop;
        n.elem := e;
    end Put;
    procedure Insert (l : in out ListT; i : Integer; e : Integer) is
        n : NodePtr := l.first;
        ins : NodePtr := new Node;
        it : Integer := 1;
    begin
        if i = 1 then
            Push(l, e);
            return;
        end if;
        if i = length(l) + 1 then
            append(l, e);
            return;
        end if;
        while it < i - 1 loop
            n := n.next;
            it := it + 1;
        end loop;

        ins.elem := e;
        ins.next := n.next;
        n.next := ins;

        l.length := l.length + 1;
    end Insert;

    procedure Print (l : ListT) is
        n : NodePtr := l.first;
    begin
        while n /= null loop
            Put (n.elem'Image);
            n := n.next;
        end loop;
        Put_Line (" (" & Length (l)'Image & " )");
    end Print;

    function Length (l : ListT) return Integer is
        i : Integer := 0;
        n : NodePtr := l.first;
    begin
        while n /= null loop
            i := i + 1;
            n := n.next;
        end loop;
        return i;
    end Length;
    procedure Clean (l : in out ListT) is
        r : Integer;
    begin
        while not isEmpty (l) loop
            r := Pop (l);
        end loop;
    end Clean;
end list;
