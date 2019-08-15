//
// Created by jputlock on 7/14/19.
//

#pragma once

#include <gtkmm/application.h>

#include "editor.h"

class EditorApplication : public Gtk::Application {
protected:
    Editor editor;

    void on_startup() override {
        Gtk::Application::on_startup();
    }

    void on_activate() override {
        Gtk::Application::on_activate();

        add_window(editor);
        this->editor.set_default_size(400, 400);

        editor.show_all();
    }

public:
    static Glib::RefPtr<EditorApplication> create(){
        return Glib::RefPtr<EditorApplication>(new EditorApplication());
    }
    virtual ~EditorApplication() {
#ifdef DEBUG
            std::cout << "Deleting EditorApplication" << std::endl;
#endif
    }
};
