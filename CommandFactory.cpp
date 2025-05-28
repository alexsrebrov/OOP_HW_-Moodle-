#include "CommandFactory.h"
#include "AddTeacherCommand.h"
#include "AddStudentCommand.h"
#include "MessageAllCommand.h"
#include "ChangePasswordCommand.h"
#include "CreateCourseCommand.h"
#include "AddToCourseCommand.h"
#include "MaillboxCommand.h"
#include "EnrollCommand.h"
#include "AssignHWCommand.h"
#include "MessageAllCommand.h"
#include "SubmiitAssignmentCommand.h"
#include "MessageCommand.h"
#include "ViewSubmissionsCommand.h"
#include "GradeAssignmentCommand.h"
#include "ClearMailboxCommand.h"
#include "GradesCommand.h"
#include "MessageStudentsCommand.h"

//			Domashno po OOP
//
//	Alexandar Srebrov 
//	FN: 2MI0600450
//	1 kurs
//	6 grupa

Command* CommandFactory::getCommand(const String& command,const User* currUser) const
{
    if (command == "add_teacher")
    {
        if (currUser->getUserType() == UserType::Admin) return new AddTeacherCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "add_student")
    {
        if (currUser->getUserType() == UserType::Admin) return new AddStudentCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "message_all")
    {
        if (currUser->getUserType() == UserType::Admin) return new MessageAllCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "change_password")     return new ChangePasswordCommand();
    else if (command == "create_course")
    {
        if (currUser->getUserType() == UserType::Teacher) return new CreateCourseCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "add_to_course")
    {
        if (currUser->getUserType() == UserType::Teacher) return new AddToCourseCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "mailbox")
    {
        if (currUser->getUserType() != UserType::Admin) return new MailboxCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "enroll")
    {
        if (currUser->getUserType() == UserType::Student) return new EnrollCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "assign_homework")
    {
        if (currUser->getUserType() == UserType::Teacher) return new AssignHWCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "message_students")
    {
        if (currUser->getUserType() == UserType::Teacher) return new MessageStudentsCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "submit_assignment")
    {
        if (currUser->getUserType() == UserType::Student) return new SubmitAssignmentCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "message")             return new MessageCommand();
    else if (command == "view_assignment_submissions")
    {
        if (currUser->getUserType() == UserType::Teacher) return new ViewSubmissiosCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "grade_assignment")
    {
        if (currUser->getUserType() == UserType::Teacher) return new GradeAssignmentCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "clear_mailbox")
    {
        if (currUser->getUserType() != UserType::Admin) return new ClearMailboxCommand();
        throw std::runtime_error("Invalid command");
    }
    else if (command == "grades")
    {
        if (currUser->getUserType() == UserType::Student) return new GradesCommand();
        throw std::runtime_error("Invalid command");
    }
    throw std::runtime_error("Inalid command");
}
