import 'package:flutter/material.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override Widget build(BuildContext context) {
    return const MaterialApp(home: TodoPage());
  }
}

class TodoPage extends StatefulWidget {
  const TodoPage({super.key});

  @override State<TodoPage> createState() => _TodoPageState();
}

class _TodoPageState extends State<TodoPage> {
  final List<String> todos = [];
  final TextEditingController controller = TextEditingController();

  void addTodo() {
    if (controller.text.isNotEmpty) {
      setState(() {
        todos.add(controller.text);
        controller.clear();
      });
    }
  }

  @override Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('To-Do List')),
      body: Column(children: [
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: Row(children: [
            Expanded(child: TextField(controller: controller)),
            IconButton(onPressed: addTodo, icon: const Icon(Icons.add)),
          ]),
        ),
        Expanded(child: ListView.builder(
          itemCount: todos.length,
          itemBuilder: (context, index) => ListTile(
            title: Text(todos[index]),
            trailing: IconButton(
              icon: const Icon(Icons.delete),
              onPressed: () => setState(() => todos.removeAt(index)),
            ),
          ),
        )),
      ]),
    );
  }
}